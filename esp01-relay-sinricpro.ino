#include <Arduino.h>
#include <ESP8266WiFi.h>

#include "SinricPro.h"
#include "SinricProSwitch.h"

#define WIFI_SSID   "WIFI_SSID"
#define WIFI_PASS   "WIFI_PASS"

#define SINRICPRO_APP_KEY     "xxx"
#define SINRICPRO_APP_SECRET  "xxx"
#define SINRICPRO_DEVICE_ID   "xxx"

#define BAUD_RATE   115200
#define RELAY_PIN   0

bool onPowerState(const String &deviceId, bool &state) {

  digitalWrite(RELAY_PIN, state);
  return true;

}

void setup() {

  Serial.begin(BAUD_RATE);
  pinMode(RELAY_PIN, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  SinricProSwitch& mySwitch = SinricPro[SINRICPRO_DEVICE_ID];
  mySwitch.onPowerState(onPowerState);

  SinricPro.begin(SINRICPRO_APP_KEY, SINRICPRO_APP_SECRET);
}

void loop() {

  SinricPro.handle();

}
