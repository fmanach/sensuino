// Handle access to the root URL
void handleRoot() {
  digitalWrite(LED_BUILTIN, HIGH);
  String replyContent = MDNS_NAME;
  replyContent += ".local\n\nHostname : ";
  replyContent += WiFi.hostname();
  replyContent += "\nIP : ";
  replyContent += WiFi.localIP().toString();
  replyContent += "\nSubnet mask : ";
  replyContent += WiFi.subnetMask().toString();
  replyContent += "\nGateway : ";
  replyContent += WiFi.gatewayIP().toString();
  replyContent += "\nDNS : ";
  replyContent += WiFi.dnsIP().toString();
  replyContent += "\nWiFi : ";
  replyContent += WiFi.SSID();
  replyContent += "\nRSSI : ";
  replyContent += WiFi.RSSI();
  replyContent += " dBm";
  webServer.send(200, "text/plain", replyContent);
  digitalWrite(LED_BUILTIN, LOW);
}

// Reply 404 to unkown requests
void handleNotFound() {
  digitalWrite(LED_BUILTIN, HIGH);
  webServer.send(404, "text/plain", "404 NOT FOUND");
  digitalWrite(LED_BUILTIN, LOW);
}

// Start web server and map requests to handlers 
void startWebServer()  {
  webServer.on("/", handleRoot);
  webServer.on("/pushButton", pushButton);
  webServer.onNotFound(handleNotFound);
  webServer.begin();
}
