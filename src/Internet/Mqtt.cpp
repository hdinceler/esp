//mqtt.cpp:
#include "Mqtt.h"
#include "../Ayar.h"
#include "Wifi.h"
 
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void mqtt_baslat(){
    mqttClient.setServer(MQTT_SERVER, MQTT_PORT);
    Serial.println("MQTT istemcisi başlatıldı");
}
void mqtt_dongu() {
    static bool onceden_baglandi=false;

    if(!wifi_baglandi()) return; // WiFi bağlı değilse MQTT bağlantısı denemesi yapma
    
    if(!mqtt_baglandi()){
        onceden_baglandi=false;
        static unsigned long onceki_zaman= 0;
        if(millis() - onceki_zaman > MQTT_BAGLANTI_DENEME_INTERVAL) { // 5 saniyede bir bağlantı denemesi yap
            onceki_zaman = millis();
            mqttClient.connect("ESP8266Client");
        }
    }

    if(!onceden_baglandi && mqtt_baglandi()) {
        onceden_baglandi=true;
        String clientId= "ESP8266Client";
        clientId+= String(random(0xffff), HEX).c_str(); // Benzersiz bir client ID oluştur
        Serial.println("MQTT'ye bağlanıldı!");
        mqttClient.subscribe(MQTT_TOPIC_ESP_DURUM);
        mqttClient.publish(MQTT_TOPIC_ESP_DURUM,clientId.c_str());
    }

    mqttClient.loop();
}
bool mqtt_baglandi() {
    return mqttClient.connected();
}

bool mqtt_yolla(const String& veri) {
    if(mqtt_baglandi()) {
        return mqttClient.publish(MQTT_TOPIC_ESP_DURUM, veri.c_str());
    }
    return false; // MQTT bağlı değilse veri gönderilemez
}