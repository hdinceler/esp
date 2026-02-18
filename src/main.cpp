//main.cpp:
#pragma once
#include "Ayar.h"
#include "Serial/Serial.h"
#include "Internet/Wifi.h"
#include "Internet/Mqtt.h"
#include "Role/Role.h"
#include "Guvenlik/Guvenlik.h"
#include "Sensorler/Sensor.h"
#include "Json/Json.h"

void setup() {
     serial_baslat();
     role_baslat();
     wifi_baslat();
     mqtt_baslat();
}

char json_sensor[128];
void loop(){
     wifi_kontrol();    
     mqtt_dongu(); 
     uint8_t nem        = nem_oku();
     int16_t sicaklik      = sicaklik_oku(); 
     uint16_t mq9        = mq9_oku();
     const char* mq9_durumu = mq9_durum(mq9);    
     if(strcmp(mq9_durumu, "tehlike") == 0) {
          role_hepsini_kapat();
          Serial.print("!!!Tehlike durumu tespit edildi! Röleler kapatıldı.\n");
          mqtt_yolla(MQTT_TOPIC_ESP_DURUM, "tehlike");
     }

     json_cevir(json_sensor, sizeof(json_sensor), 3, "n", nem, "s", sicaklik, "mq9", mq9);

     mqtt_yolla(MQTT_TOPIC_SENSOR, json_sensor);

     Serial.print("Nem: "); Serial.println(nem);
     Serial.print("Sicaklik: "); Serial.println(sicaklik);
     Serial.print("MQ9: "); Serial.println(mq9);
     Serial.print("MQ9 Durumu: "); Serial.println(mq9_durumu);
     Serial.println(""); 
     delay(1000); // 1 saniye bekle
}