//main.cpp:
#include "serial/serial.h"
#include "Wifi/Wifi.h"

void setup() {
seriali_baslat();
}

void loop(){
   char gelen_veri = seriali_oku();
    if (gelen_veri != '\0') {
        // Gelen veriyi işleyin
        Serial.print("Gelen veri: ");
        Serial.println(gelen_veri);
    }
}