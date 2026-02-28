#include "lcd.h"


void lcd_baslat(){
    Wire.begin(D2,D1);
    lcd.init();          
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("merhaba");
    


}