// Function starting the device by calling starter functions
void startDevice() {
  startWifi(WFSSID, WFPSK);
  startMDNS(MDNS_NAME);
  startWebServer();
  blinkStatus(100, 10);
}

// Blink the built-in LED to indicate the status of operations
void blinkStatus(int blinkDelay, int blinkNumber) {
  int blinkCount;
  for (blinkCount = 0; blinkCount < blinkNumber; blinkCount++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(blinkDelay);
    digitalWrite(LED_BUILTIN, LOW);
    delay(blinkDelay);
  }
}

// Initiate the WiFi connection
void startWifi(char* ssid, char* key) {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WFSSID, WFPSK);
  while (WiFi.status() != WL_CONNECTED) {
    blinkStatus(1000, 1);
  }
  if(SERIAL_DEBUG) {
    Serial.println("");
    Serial.print("IP : ");
    Serial.println(WiFi.localIP());
  }
}

// Start the mDNS service
void startMDNS(char* mdnsName) {
  if(MDNS.begin(mdnsName)) {
    blinkStatus(500, 5);
    if(SERIAL_DEBUG) {
      Serial.println("mDNS OK");
    }
  }
}

// Check for disconnection and restart the init process  
void keepWifiAlive() {
  if(!WiFi.isConnected()) {
    if(SERIAL_DEBUG) {
      Serial.println("WiFi KO");
    }
    startDevice();
  }
}
