//Taklid.h:
#pragma once
#include "../../Ayar.h"
#include <Arduino.h>
#include "../../Serial/Serial.h"
#include "../../Internet/Wifi.h"
#include "../../Internet/Mqtt.h"

void taklid_baslat();
uint8_t nem_oku();
float sicaklik_oku();
uint16_t mq9_oku();
uint8_t roleleri_oku();
String taklid_veri_uret();
void taklid_gonder();