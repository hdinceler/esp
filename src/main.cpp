//main.cpp:
#pragma once
#include "Ayar.h"
#include "Serial/Serial.h"
#include "Internet/Wifi.h"
#include "Internet/Mqtt.h"
#include "Role/Role.h"
#include "Sensorler/Sensor.h"
#include "Json/Json.h"

void setup() {
     serial_baslat();
     role_baslat();
     wifi_baslat();
     mqtt_baslat();
     role_hepsini_kapat();
}

char json_sensor[128];
// Önceki değerleri saklamak için global değişkenler
uint8_t  prev_nem       = 0xFF;   // olası değer dışı başlangıç
int16_t  prev_sicaklik  = 0x7FFF; // olası değer dışı başlangıç
uint16_t prev_mq9       = 0xFFFF;

void loop(){
     uint16_t mq9= mq9_oku();
     if( gaz_kacagi_var() ) {
          role_hepsini_kapat();
          
     }


}