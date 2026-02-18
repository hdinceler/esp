#include "Sensor.h"

uint8_t nem_oku(){
    // Gerçek sensör okuma kodu buraya gelecek
    return random(30, 80); // Örnek: 30 ile 80 arasında rastgele bir nem değeri döndür
}
int16_t sicaklik_oku() {
    // 12.00 ile 60.00 arasında rastgele float
    float sicaklik = 12.0 + ((float)random(0, 4800) / 100.0); 
    // 1356 gibi tam sayı istiyorsan 100 ile çarp
    return (int16_t)(sicaklik * 100);  // Örn: 13.56 → 1356
}

uint16_t mq9_oku(){
    // Gerçek sensör okuma kodu buraya gelecek
    return random(200, 800); // Örnek: 200 ile 800 arasında rastgele bir MQ-9 gaz sensör değeri döndür
}