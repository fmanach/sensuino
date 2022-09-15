// Simulate a push on the button
void pushButton() {
  digitalWrite(LED_BUILTIN, HIGH);  
  digitalWrite(PIN_SENSEO, HIGH);
  delay(500);
  digitalWrite(PIN_SENSEO, LOW);
  webServer.send(200, "text/plain", "OK");
  if(SERIAL_DEBUG) {
    Serial.println("Button pressed");
  }
  digitalWrite(LED_BUILTIN, LOW);
}
