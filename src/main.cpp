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
     String taklid_veri=taklid_veri_uret();
     if( mqtt_yolla(MQTT_TOPIC_SENSOR,taklid_veri) ){
         Serial.println("Taklid veri gonderildi:");
         Serial.println(taklid_veri);
     } else {
         Serial.println("MQTT gonderim basarisiz");
     }
     delay(1000); // 1 saniye bekle

}