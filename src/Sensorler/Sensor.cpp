#include "Sensor.h"
#include "../Ayar.h"


// Önceki değerler, sadece bu cpp içinde saklanır
static uint8_t  prev_nem      = 0xFF;
static int16_t  prev_sicaklik = 0x7FFF;
static uint16_t prev_mq9      = 0xFFFF;

// Son okuma zamanı
static unsigned long son_okuma = 0;

// -------------------- Sensör Okuma --------------------
uint8_t nem_oku() {
    return random(30, 80);
}

int16_t sicaklik_oku() {
    float sicaklik = 12.0 + ((float)random(0, 4800) / 100.0);
    return (int16_t)(sicaklik * 100); // 13.56 -> 1356
}

uint16_t mq9_oku() {
    return random(200, 800);
}

// -------------------- MQ9 Durum --------------------
const char* mq9_durum(uint16_t mq9_degeri) {

    if (mq9_degeri < MQ_SINIR_UYGUN)  return "uygun";
    if (mq9_degeri < MQ_SINIR_KRITIK) return "kritik";
    return "tehlike";
}

bool gaz_kacagi_var() {
    return mq9_oku() >= MQ_SINIR_KRITIK;
}
// -------------------- Değişim ve Interval Kontrol --------------------
bool sensorlari_guncelle(uint8_t* nem, int16_t* sicaklik, uint16_t* mq9, unsigned long interval) {
    unsigned long now = millis();

    // Interval geçmediyse false dön
    if (now - son_okuma < interval) return false;
    son_okuma = now;

    // Sensörleri oku
    *nem      = nem_oku();
    *sicaklik = sicaklik_oku();
    *mq9      = mq9_oku();

     

    // Değer değiştiyse true dön
    if (*nem != prev_nem || *sicaklik != prev_sicaklik || *mq9 != prev_mq9) {
        prev_nem      = *nem;
        prev_sicaklik = *sicaklik;
        prev_mq9      = *mq9;
        return true;
    }

    return false;
}
