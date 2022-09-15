// Sensuino
//
// Created : Sept 2022 by @fmanach
// https://github.com/fmanach/sensuino
// 
//
// My connected Senseo coffee maker

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>

// User has to set the WiFi credentials in wifi.h
#include "wifi.h"

// Activate console loggin (9600 bauds) ?
#define SERIAL_DEBUG false

// Define the mDNS name
// Device will be reachable at MDNS_NAME.local
#define MDNS_NAME "Sensuino"

// My Senseo will be commanded on pin D1 which is GPIO5
#define PIN_SENSEO 5 

// Global objects
ESP8266WebServer webServer(80);

void setup() {
  if(SERIAL_DEBUG) {
    Serial.begin(9600);
  }
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_SENSEO, OUTPUT);
  startDevice();
}

void loop() {
  keepWifiAlive();
  webServer.handleClient();
  MDNS.update();
}
