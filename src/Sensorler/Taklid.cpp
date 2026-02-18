//Taklid.cpp:
#include "Taklid.h"
void taklid_baslat() {
    Serial.println("Taklid sensör başlatıldı");
}

uint8_t nem_oku(){
    return random(30, 80); // Örnek: 30 ile 80 arasında rastgele bir nem değeri döndür
}
float sicaklik_oku(){
    return random(15, 35); // Örnek: 15 ile 35 arasında rastgele bir sıcaklık değeri döndür
}

uint16_t mq9_oku(){
    return random(200, 800); // Örnek: 200 ile 800 arasında rastgele bir MQ-9 gaz sensör değeri döndür
}

 


String taklid_veri_uret() {
    String json_verisi = "{";
    json_verisi += "\"n\": " + String(nem_oku()) + ",";
    json_verisi += "\"s\": " + String(sicaklik_oku()) + ",";
    json_verisi += "\"mq9\": " + String(mq9_oku()) + ",";
    json_verisi += "\"r\": " + String(roleleri_oku());
    json_verisi += "}"; 
    
    return json_verisi;
    }

void taklid_gonder() {
    static unsigned long onceki_zaman = 0;

    if (millis() - onceki_zaman < TAKLIT_GONDER_INTERVAL)
        return;

    onceki_zaman = millis();

    String veri = taklid_veri_uret();

    if (mqtt_yolla(veri)) {
        Serial.println("Taklit veri gonderildi:");
        Serial.println(veri);
    } else {
        Serial.println("MQTT gonderim basarisiz");
    }
}
