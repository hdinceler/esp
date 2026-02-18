#ifndef AYARLAR_H
#define AYARLAR_H

// ================= ZAMANLAMA =================
#define MQTT_BAGLANTI_DENEME_INTERVAL   5000   // 5 sn
#define WIFI_BAGLANTI_DENEME_INTERVAL   5000   // 5 sn
#define SERIAL_BAGLANTI_DENEME_INTERVAL 2000   // 2 sn

#define MQTT_DONGU_INTERVAL             1000   // 1 sn
#define WIFI_DONGU_INTERVAL             5000   // 5 sn
#define SERIAL_DONGU_INTERVAL            500   // 0.5 sn
#define TAKLIT_GONDER_INTERVAL          1000   // 1 sn

// ================= WIFI ======================
#define WIFI_SSID     "zone-linux"
#define WIFI_PASSWORD "Strangula57+"

// ================= MQTT ======================
#define MQTT_SERVER "haysaf.com"
#define MQTT_PORT   1883

#define MQTT_TOPIC_ROLE       "ev/roleler"
#define MQTT_TOPIC_SENSOR     "ev/sensorler"
#define MQTT_TOPIC_ESP_DURUM  "ev/esp_durum"

// ================= SERIAL ====================
#define SERIAL_BAUD 115200

// ================= RÖLE ======================
// NodeMCU 0.9 (ESP8266) BOOT-SAFE pinler
// D1(GPIO5)  D2(GPIO4)  D5(GPIO14)  D6(GPIO12)
#define ROLE_SAYISI 4
#define ROLE_PINLERI { D1, D2, D5, D6 }

// Röle aktif LOW ise true yap
#define ROLE_AKTIF_LOW true

// ================= BUZZER ===================
// M9 / Aktif buzzer için ideal
#define BUZZER_PIN D0   // GPIO16

// ================= DHT11 ====================
#define DHT_PIN  D4     // GPIO2
#define DHT_TIP  DHT11

#endif // AYARLAR_H

// ================= RÖLE ======================
// NodeMCU 0.9 (ESP8266) BOOT-SAFE pinler
// D1(GPIO5)  D2(GPIO4)  D5(GPIO14)  D6(GPIO12)
#define ROLE_SAYISI 4
#define ROLE_PINLERI { D1, D2, D5, D6 }

// Röle aktif LOW ise true yap
#define ROLE_AKTIF_LOW true
