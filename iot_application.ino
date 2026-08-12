#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Fire Alert System"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

#define FLAME_SENSOR_PIN 34
#define BUZZER_PIN 27

bool flamePreviouslyDetected = false;

void setup() {
  Serial.begin(115200);
  pinMode(FLAME_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("Connecting to Blynk...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();

  int flame = digitalRead(FLAME_SENSOR_PIN);

  if (flame == LOW && !flamePreviouslyDetected) {
    flamePreviouslyDetected = true;
    Serial.println("Flame detected");
    tone(BUZZER_PIN, 1000);
    Blynk.logEvent("fire_alert", "Fire detected. Evacuate immediately.");
  }

  if (flame == HIGH && flamePreviouslyDetected) {
    flamePreviouslyDetected = false;
    Serial.println("Flame cleared");
    noTone(BUZZER_PIN);
  }

  delay(50);
}
