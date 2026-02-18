#include "Guvenlik.h"
#include "../Ayar.h"
// gaz seviyesi ölçümüne göre  5 karakter char dizi söndürür : 
// 4 farklı seviye var : uygun,kritk,tehlk . tehlikeye gelince röleleri kapatır

// const char* ile Sabit stringler FLASH/ROM’da tutulur, RAM harcanmaz
const char* mq9_durum(uint16_t mq9_degeri) {
    if (mq9_degeri < MQ_SINIR_UYGUN) return "uygun";
    if (mq9_degeri < MQ_SINIR_KRITIK) return "kritik";
    // MQ_SINIR_TEHLIKELI ve üstü → tehlike
    return "tehlike";
}
