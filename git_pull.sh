#!/bin/bash

BRANCH="main"
REMOTE="origin"

echo "⚠️  Tüm local değişiklikler silinecek..."

# Fetch
git fetch $REMOTE

# Local değişiklikleri sil
git reset --hard $REMOTE/$BRANCH

# Takip edilmeyen dosyaları sil
git clean -fd

echo "✅ Local repo, remote ile birebir aynı hale getirildi."
