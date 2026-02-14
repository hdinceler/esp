//main.cpp:
#include "Ayar.h"
#include "serial/serial.h"
#include "Wifi/Wifi.h"

void setup() {
seriali_baslat();
wifi_baslat(  WIFI_SSID, WIFI_PASSWORD  );
}

void loop(){
   char gelen_veri = seriali_oku();
    if (gelen_veri != '\0') {
        // Gelen veriyi işleyin
        Serial.print("Gelen veri: ");
        Serial.println(gelen_veri);
    }
}