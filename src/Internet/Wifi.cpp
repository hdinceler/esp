//Wifi.h:

#include "Internet/Wifi.h"
 void wifi_baslat(){
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("WiFi'ye bağlanılıyor");
    while (WiFi.status() != WL_CONNECTED) {
        delay(200);
        Serial.print(".");
    }
    Serial.println("\nWiFi'ye bağlanıldı!");
    Serial.print("IP Adresi: ");
    Serial.println(WiFi.localIP());
 }

 void wifi_kontrol() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi bağlantısı kesildi, yeniden bağlanılıyor...");
        wifi_baslat();
    }
 }
 bool wifi_baglandi() {
    return WiFi.status() == WL_CONNECTED;
 }