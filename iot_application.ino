#define BLYNK_TEMPLATE_ID "TMPL3DzatQEzc"
#define BLYNK_TEMPLATE_NAME "Fire Alert System"
#define BLYNK_AUTH_TOKEN "PIRdViLvuDjaPB37fEPGUKjhfx9UCdYV"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "HS2006";
char pass[] = "S@hoo123454";

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

  // --- FLAME DETECTED ---
  if (flame == LOW && flamePreviouslyDetected == false) {
    flamePreviouslyDetected = true;  

    Serial.println("🔥 FLAME DETECTED!");
    tone(BUZZER_PIN, 1000);

    // Trigger Blynk event ONLY when state changes
    Blynk.logEvent("fire_alert", "FIRE DETECTED! Evacuate Immediately!");
  }

  // --- FLAME GONE ---
  if (flame == HIGH && flamePreviouslyDetected == true) {
    flamePreviouslyDetected = false;   

    Serial.println("🔥 Flame cleared.");
    noTone(BUZZER_PIN);
  }

  delay(50);  
}
