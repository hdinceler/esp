#include "komut/komut.h"

void setup() {
  komut_ayaga_kaldir();
  // mqtt_ayaga_kaldir()
}

void loop() {
  uint16_t komut = komut_oku();
  if (komut != 0) {
    Serial.print("Komut alındı: ");
    Serial.println(komut);
    // Komutu işleme kodu buraya gelecek
  }
}
 