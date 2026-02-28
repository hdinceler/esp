#pragma once
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <Wire.h>
#include "../Ayar.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);


void lcd_baslat();
    


