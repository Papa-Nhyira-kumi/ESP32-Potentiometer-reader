// Use one of ESP32's ADC1-compatible pins (GPIO34 is safe and analog-only)
const int potPin = 34;

void setup() {
  Serial.begin(115200);               // Initialize serial communication
  delay(1000);                        // Small delay to ensure serial monitor starts
  Serial.println("Potentiometer Reader Initialized");
}

void loop() {
  // Read raw analog value (0 to 4095)
  int rawValue = analogRead(potPin);

  // Convert raw value to voltage (ESP32 uses 3.3V reference)
  float voltage = (rawValue / 4095.0) * 3.3;

  // Print both values
  Serial.print("Raw ADC Value: ");
  Serial.print(rawValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 3); // 3 decimal places
  Serial.println(" V");

  delay(200); // Delay for readability
}
