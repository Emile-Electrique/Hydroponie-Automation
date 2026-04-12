#include <WiFi.h>

const char* ssid = "test24";
const char* password = "test12345";

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.mode(WIFI_STA);
  WiFi.setSleep(false);
  WiFi.disconnect(true, true);
  delay(500);

  WiFi.begin(ssid, password);

  Serial.println("Connecting...");
  unsigned long t0 = millis();

  while (millis() - t0 < 15000) {
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("Connected");
      Serial.println(WiFi.localIP());
      return;
    }
    delay(300);
    Serial.print(".");
  }

  Serial.println("\nFailed");
}
void loop() {}