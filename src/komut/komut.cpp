#include "komut.h"

void komut_ayaga_kaldir() {
    Serial.begin(115200);
    Serial.println("Komut sistemi başlatıldı.");
}

uint16_t komut_oku(){
    if (Serial.available() > 0) {
        String komutStr = Serial.readStringUntil('\n');
        komutStr.trim();
        return komutStr.toInt();
    }
    return 0; // Geçerli bir komut yoksa 0 döndür
}