#include "Wifi/Wifi.h"

void wifi_baslat(const char* ssid, const char* password) {
    WiFi.begin(ssid, password);
    Serial.print("WiFi'ye bağlanılıyor");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi bağlantısı başarılı!");
    Serial.print("IP Adresi: ");
    Serial.println(WiFi.localIP());
}

bool wifi_baglandi_mi() {
    return WiFi.status() == WL_CONNECTED;
}