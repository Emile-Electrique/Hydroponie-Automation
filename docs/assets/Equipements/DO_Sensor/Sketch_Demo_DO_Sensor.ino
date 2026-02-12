// ESP32 ADC Read on GPIO 13 and 14
// Outputs to Serial Plotter

const int pin1 = 13;
const int pin2 = 14;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Optional: set ADC resolution (default is 12-bit = 0–4095)
  analogReadResolution(12);

  Serial.println("ADC13 ADC14"); // Header for Serial Plotter
}

void loop() {

  int adc13 = analogRead(pin1);
  int adc14 = analogRead(pin2);

  // Print in format: value1 value2
  // (space separated for Serial Plotter)
  Serial.print(adc13);
  Serial.print(" ");
  Serial.println(adc14);

  delay(200); // ~5 samples per second
}
