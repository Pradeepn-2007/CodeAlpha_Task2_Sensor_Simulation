/*
  ============================================================
   Temperature-Based IoT Alert System
   CodeAlpha - Internet of Things (IoT) Internship
   Task 2: Sensor-Based Simulation
  ============================================================

  Description:
  This project reads the ambient temperature using an LM35
  temperature sensor connected to an Arduino Uno. The analog
  reading is converted into degrees Celsius and printed to the
  Serial Monitor once every second.

  If the temperature is greater than or equal to 30 degrees
  Celsius, an LED is turned ON as a visual alert. If the
  temperature drops below 30 degrees Celsius, the LED is
  turned OFF.

  Hardware connections:
  - LM35 VCC  -> Arduino 5V
  - LM35 GND  -> Arduino GND
  - LM35 OUT  -> Arduino A0
  - LED Anode (+)  -> 220 ohm resistor -> Arduino Digital Pin 8
  - LED Cathode (-) -> Arduino GND

  Simulation platform: Tinkercad Circuits
  ============================================================
*/

// ---------------- Pin Definitions ----------------
const int LM35_PIN = A0;   // LM35 OUT pin connected to Analog pin A0
const int LED_PIN   = 8;   // LED connected to Digital pin 8

// ---------------- Constants -----------------------
const float TEMP_THRESHOLD  = 30.0;   // Alert threshold in Celsius
const float VOLTAGE_REF     = 5.0;    // Arduino reference voltage (5V)
const float ADC_RESOLUTION  = 1024.0; // Arduino Uno has a 10-bit ADC (0-1023)

void setup() {
  // Start Serial communication so we can view readings on the Serial Monitor
  Serial.begin(9600);

  // Configure the LED pin as an output
  pinMode(LED_PIN, OUTPUT);

  // Make sure the LED starts in the OFF state
  digitalWrite(LED_PIN, LOW);

  Serial.println("Temperature-Based IoT Alert System Started...");
  Serial.println("========================================");
  delay(1000);
}

void loop() {
  // ---- Step 1: Read the raw analog value from the LM35 sensor ----
  // analogRead() returns a value between 0 and 1023
  int rawValue = analogRead(LM35_PIN);

  // ---- Step 2: Convert the raw ADC value into a voltage ----
  // voltage = (rawValue / max ADC steps) * reference voltage
  float voltage = (rawValue / ADC_RESOLUTION) * VOLTAGE_REF;

  // ---- Step 3: Convert voltage into temperature in Celsius ----
  // The LM35 outputs 10 mV (0.01V) for every 1 degree Celsius,
  // so multiplying the voltage by 100 gives the temperature.
  float temperatureC = voltage * 100.0;

  // ---- Step 4: Display the temperature on the Serial Monitor ----
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  // ---- Step 5: Compare the temperature with the threshold ----
  if (temperatureC >= TEMP_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);              // Turn the LED ON
    Serial.println("Status: ALERT - Temperature High! LED is ON");
  } else {
    digitalWrite(LED_PIN, LOW);               // Turn the LED OFF
    Serial.println("Status: Normal - LED is OFF");
  }

  Serial.println("----------------------------------------");

  // ---- Step 6: Wait 1 second before taking the next reading ----
  delay(1000);
}
