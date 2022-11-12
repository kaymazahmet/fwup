
#ifndef _FW_UP_H
#define _FW_UP_H

#include "Arduino.h"
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>


class _FW_UP {

  private:

    const char* Name0 = "";
    const char* Pass0 = "";

    public:
    _FW_UP(const char* ssid, const char* password);
    void Load();
    void Let();
    void Active();

};

#endif