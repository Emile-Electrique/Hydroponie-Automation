// ESP32 4-20mA reader using 150 ohm shunt resistor to GND on GPIO13
// Prints raw ADC and calculated current (mA)

#include <Arduino.h>

static const int   ADC_PIN = 13;     // GPIO13 (ADC2 on many ESP32 variants)
static const float SHUNT_OHMS = 150.0f;

void setup() {
  Serial.begin(115200);
  delay(300);

  // ESP32 ADC setup
  analogReadResolution(12); // 0..4095
  analogSetPinAttenuation(ADC_PIN, ADC_11db); // ~0-3.3V range (board-dependent)

  Serial.println("ESP32 4-20mA reader (150 ohm shunt) starting...");
}

void loop() {
  // Raw ADC
  int raw = analogRead(ADC_PIN);

  // Best effort voltage conversion:
  // On many ESP32 Arduino cores, this returns a calibrated-ish millivolt value.
  uint32_t mv = analogReadMilliVolts(ADC_PIN);
  float volts = mv / 1000.0f;

  // Current through shunt (I = V/R)
  float mA = (volts / SHUNT_OHMS) * 1000.0f;

  // Print
  Serial.print("raw=");
  Serial.print(raw);
  Serial.print("  mv=");
  Serial.print(mv);
  Serial.print("  mA=");
  Serial.println(mA, 3);

  delay(200);
}
