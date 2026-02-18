//mqtt.h:
#pragma once
#include <Arduino.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "../Ayar.h"
#include "Wifi.h"
#include "../Role/Role.h"


void mqtt_baslat();
void mqtt_dongu();
bool mqtt_baglandi();
bool mqtt_yolla(const char* topic, const String& veri) ;

// ===== JSON API =====
bool mqtt_json_var_mi();
bool mqtt_json_al(JsonDocument& doc);
