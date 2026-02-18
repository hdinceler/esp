#include "Mqtt.h"

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

// ===== JSON buffer =====
static StaticJsonDocument<256> gelen_json;
static bool json_hazir = false;

// ===== MQTT CALLBACK =====
void mqtt_callback(char* topic, byte* payload, unsigned int length)
{
    // payload[length] = '\0'; // string sonlandır

    DeserializationError err =
        deserializeJson(gelen_json, payload,length);

    if (err) {
        Serial.println("JSON parse hatasi!");
        return;
    }

    json_hazir = true;

    Serial.print("MQTT JSON alindi [");
    Serial.print(topic);
    Serial.println("]");
}

// ===== MQTT BASLAT =====
void mqtt_baslat(){
    mqttClient.setServer(MQTT_SERVER, MQTT_PORT);
    mqttClient.setCallback(mqtt_callback);
    Serial.println("MQTT istemcisi baslatildi");
}

// ===== MQTT DONGU =====
void mqtt_dongu() {
    static bool onceden_baglandi = false;
    static unsigned long onceki_zaman = 0;

    if (!wifi_baglandi()) return;

    if (!mqtt_baglandi()) {
        onceden_baglandi = false;

        if (millis() - onceki_zaman > MQTT_BAGLANTI_DENEME_INTERVAL) {
            onceki_zaman = millis();

            String clientId = "ESP8266-";
            clientId += String(ESP.getChipId(), HEX);

            mqttClient.connect(clientId.c_str());
        }
    }

    if (!onceden_baglandi && mqtt_baglandi()) {
        onceden_baglandi = true;

        Serial.println("MQTT'ye baglanildi!");

        mqttClient.subscribe(MQTT_TOPIC_ROLE);
        // mqttClient.subscribe(MQTT_TOPIC_ESP_DURUM);
    }

    mqttClient.loop();
}

// ===== DURUM =====
bool mqtt_baglandi() {
    return mqttClient.connected();
}

// ===== GONDER =====
bool mqtt_yolla(const char* topic, const String& veri) {
    if (!mqtt_baglandi()) return false;
    return mqttClient.publish(topic, veri.c_str());
}

// ===== JSON OKUMA API =====
bool mqtt_json_var_mi()
{
    return json_hazir;
}

bool mqtt_json_al(JsonDocument& doc)
{
    if (!json_hazir) return false;

    doc.clear();
    doc.set(gelen_json);
    json_hazir = false;
    return true;
}


void mqtt_json_isle(JsonDocument& json)
{
    // --- Alan kontrolü ---
    if (!json.containsKey("r")) {
        Serial.println("JSON'da role mask yok!");
        return;
    }

    // --- Değerler ---
    uint8_t nem       = json["n"] | 0;
    int8_t  sicaklik  = json["s"] | 0;
    uint16_t mq9      = json["g"] | 0;
    uint8_t roleMask  = json["r"];

    // --- Röle uygula ---
    role_maskesi_uygula(roleMask);

    // --- Debug ---
    Serial.print("Nem: "); Serial.println(nem);
    Serial.print("Sicaklik: "); Serial.println(sicaklik);
    Serial.print("MQ9: "); Serial.println(mq9);
    Serial.print("Role mask: "); Serial.println(roleMask, BIN);
}