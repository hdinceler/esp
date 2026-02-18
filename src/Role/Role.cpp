#include "Role.h"
#include "../Ayar.h"
// ================== PIN DİZİSİ ==================
static const uint8_t role_pinleri[ROLE_SAYISI] = ROLE_PINLERI;

// ================== STATE ==================
static uint8_t role_maskesi = 0x00;

// ================== YARDIMCI ==================
static inline uint8_t role_acik_seviye() {
    return ROLE_AKTIF_LOW ? LOW : HIGH;
}

static inline uint8_t role_kapali_seviye() {
    return ROLE_AKTIF_LOW ? HIGH : LOW;
}

// ================== API ==================
void role_baslat() {
    for (uint8_t i = 0; i < ROLE_SAYISI; i++) {
        pinMode(role_pinleri[i], OUTPUT);
        digitalWrite(role_pinleri[i], role_kapali_seviye());
    }
    role_maskesi = 0x00;
}


void role_maskesi_uyugla(uint8_t mask) {
    role_maskesi = mask;

    for (uint8_t i = 0; i < ROLE_SAYISI; i++) {
        bool acik = (mask >> i) & 0x01;
        digitalWrite(
            role_pinleri[i],
            acik ? role_acik_seviye() : role_kapali_seviye()
        );
    }
}

uint8_t role_maskesi_getir() {
    return role_maskesi;
}

void role_hepsini_ac() {
    role_maskesi_uyugla((1 << ROLE_SAYISI) - 1);
}

void role_hepsini_kapat() {
    role_maskesi_uyugla(0x00);
}
