#!/bin/bash

# ==============================
# CONFIG
# ==============================
REMOTE_NAME="origin"
REMOTE_URL="git@github.com:hdinceler/esp.git"
BRANCH="main"

# ==============================
# SAFETY CHECK
# ==============================
if [ "$EUID" -eq 0 ]; then
  echo "⚠️  UYARI: root olarak çalıştırıyorsun."
  echo "   Git çalışır ama önerilmez."
  echo
fi

# ==============================
# INIT REPO IF NEEDED
# ==============================
if [ ! -d ".git" ]; then
  echo "📁 Git repo yok → git init"
  git init || exit 1
fi

# ==============================
# REMOTE CHECK
# ==============================
if ! git remote | grep -q "^${REMOTE_NAME}$"; then
  echo "🔗 Remote ekleniyor: $REMOTE_URL"
  git remote add "$REMOTE_NAME" "$REMOTE_URL" || exit 1
else
  echo "🔗 Remote mevcut"
fi

# ==============================
# BRANCH CHECK
# ==============================
git branch --list "$BRANCH" >/dev/null 2>&1
if [ $? -ne 0 ]; then
  echo "🌿 Branch oluşturuluyor: $BRANCH"
  git checkout -b "$BRANCH" || exit 1
else
  git checkout "$BRANCH" || exit 1
fi

# ==============================
# ADD & COMMIT
# ==============================
git add .

if git diff --cached --quiet; then
  echo "✅ Commit edilecek değişiklik yok"
else
  COMMIT_MSG="Auto commit: $(date '+%Y-%m-%d %H:%M:%S')"
  echo "📝 Commit atılıyor: $COMMIT_MSG"
  git commit -m "$COMMIT_MSG" || exit 1
fi

# ==============================
# PUSH LOGIC
# ==============================
echo "🚀 Push deneniyor..."

git push -u "$REMOTE_NAME" "$BRANCH"
if [ $? -ne 0 ]; then
  echo "⚠️ Normal push başarısız → force push deneniyor (ilk kurulum olabilir)"
  git push -u "$REMOTE_NAME" "$BRANCH" --force || exit 1
fi

echo "✅ Git push tamamlandı"
