//mqtt.h:
#pragma once
#include <Arduino.h>
#include <PubSubClient.h>

void mqtt_baslat();
void mqtt_dongu();
bool mqtt_baglandi();
bool mqtt_yolla(const String& veri);