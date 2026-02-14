#include "mqtt.h"
#include "../Ayar.h"
#include "Wifi.h"
const char* mqtt_server = MQTT_SERVER; // Örnek ücretsiz broker
const int mqtt_port = MQTT_PORT;
const char* mqtt_topic  = MQTT_TOPIC;
WiFiClient espClient;
PubSubClient client(espClient);

void mqtt_baglan() {
  client.setServer(mqtt_server, mqtt_port);
  while (!client.connected()) {
    Serial.print("MQTT'ye bağlanılıyor...");
    if (client.connect("ESP8266Client")) {
      Serial.println("Bağlandı!");
    } else {
      Serial.print("Bağlantı başarısız, rc=");
      Serial.print(client.state());
      Serial.println(" 5 saniye sonra tekrar denenecek");
      delay(5000);
    }
  }
}

void mqtt_reconnect() {
  if (!client.connected()) {
    mqtt_baglan();
  }
  client.loop();
}


 