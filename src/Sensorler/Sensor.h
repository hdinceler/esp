#pragma once
#include "Sensor.h"
#include "../Ayar.h"
#include <Arduino.h>

uint8_t nem_oku();
int16_t sicaklik_oku();
uint16_t mq9_oku();
const char* mq9_durum(uint16_t mq9);

bool gaz_kacagi_var();
// SENSOR_OKUMA_INTERVAL milis aralıkla değişen değerler olursa true ile bildir
bool sensorlari_guncelle(uint8_t* nem, int16_t* sicaklik, uint16_t* mq9, unsigned long interval);