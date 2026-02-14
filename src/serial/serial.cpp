//serial:cpp:
#include "serial.h"

void seriali_baslat(){
    Serial.begin(115200);
    Serial.println("Serial başladı");
}
char seriali_oku(){
    if (Serial.available() > 0) {
        char data = Serial.read();
        Serial.print("Gelen veri: ");
        Serial.println(data);
        return data;
    }
    return '\0'; // Veri yoksa null karakter döndür
}