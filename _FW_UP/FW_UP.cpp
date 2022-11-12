
#include "Arduino.h"
#include "_FW_UP.h"

    _FW_UP::_FW_UP(const char* ssid, const char* password){

    Name0 = ssid;
    Pass0 = password;
    }

void _FW_UP::Load() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(Name0, Pass0);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi baglantisi basarisiz! Yeniden baslatiliyor...");
    delay(5);
    ESP.restart();
  }
}

void _FW_UP::Let(){
  ArduinoOTA
    .onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";
    })
    .onEnd([]() {
    })
    .onProgress([](unsigned int progress, unsigned int total) {
    })
    .onError([](ota_error_t error) {
      if (error == OTA_AUTH_ERROR);
      else if (error == OTA_BEGIN_ERROR);
      else if (error == OTA_CONNECT_ERROR);
      else if (error == OTA_RECEIVE_ERROR);
      else if (error == OTA_END_ERROR);
    });

    ArduinoOTA.begin();
    
}
void _FW_UP::Active(){
  ArduinoOTA.handle();
}