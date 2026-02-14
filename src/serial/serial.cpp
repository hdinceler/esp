//serial:cpp:
#include "serial.h"

void seriali_baslat() {
    Serial.begin(SERIAL_BAUD);
    Serial.println("Serial başladı");
}

char seriali_oku() {
    if (Serial.available() > 0) {
        int data = Serial.read(); // Tek karakter oku
        return (char)data;        // int → char dönüşümü
    }
    return '\0'; // Veri yoksa null karakter döndür
}
