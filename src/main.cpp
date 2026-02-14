//main.cpp:
#pragma once
#include "Ayar.h"
#include "Serial/Serial.h"
#include "Internet/Wifi.h"
#include "Internet/Mqtt.h"
#include "Cikis/Sensorler/Taklid.h"

void setup() {
seriali_baslat();
wifi_baslat();
mqtt_baslat();
}

void loop(){
      wifi_kontrol();
      mqtt_dongu();
      taklid_gonder();
}