//main.cpp:
#pragma once
#include "Ayar.h"
#include "Serial/Serial.h"
#include "Internet/Wifi.h"
#include "Internet/Mqtt.h"
#include "Role/Role.h"
#include "Sensorler/Taklid.h"

void setup() {
serial_baslat();
role_baslat();
wifi_baslat();
mqtt_baslat();
taklid_baslat();
}

void loop(){
     wifi_kontrol();    
     mqtt_dongu(); 
     taklid_gonder();
}