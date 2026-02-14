//main.cpp:
#pragma once
#include "Ayar.h"
#include "serial/serial.h"
#include "Internet/Wifi.h"

void setup() {
seriali_baslat();
wifi_baslat(  WIFI_SSID, WIFI_PASSWORD  );
}

void loop(){
  //  char gelen_veri = seriali_oku();
    
}