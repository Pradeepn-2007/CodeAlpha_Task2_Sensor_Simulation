/*
  ============================================================
   Temperature-Based IoT Alert System
   CodeAlpha - Internet of Things (IoT) Internship
   Task 2: Sensor-Based Simulation
  ============================================================

  Description:
  This project reads the ambient temperature using a TMP36
  temperature sensor connected to an Arduino Uno. (Note: Tinkercad
  Circuits does not have an LM35 component in its parts library --
  the "Temperature Sensor" part it provides is actually a TMP36.
  It has the same 3-pin VCC/OUT/GND layout, but a different
  voltage-to-temperature formula, which is used below.) The analog
  reading is converted into degrees Celsius and printed to the
  Serial Monitor once every second.

  If the temperature is greater than or equal to 30 degrees
  Celsius, an LED is turned ON as a visual alert. If the
  temperature drops below 30 degrees Celsius, the LED is
  turned OFF.

  Hardware connections:
  - TMP36 VCC  -> Arduino 5V
  - TMP36 GND  -> Arduino GND
  - TMP36 OUT  -> Arduino A0
  - LED Anode (+)  -> 220 ohm resistor -> Arduino Digital Pin 8
  - LED Cathode (-) -> Arduino GND

  Simulation platform: Tinkercad Circuits
  ============================================================
*/

// ---------------- Pin Definitions ----------------
const int TMP36_PIN = A0;   // TMP36 OUT pin connected to Analog pin A0
const int LED_PIN    = 8;   // LED connected to Digital pin 8

// ---------------- Constants -----------------------
const float TEMP_THRESHOLD  = 30.0;   // Alert threshold in Celsius
const float VOLTAGE_REF     = 5.0;    // Arduino reference voltage (5V)
const float ADC_RESOLUTION  = 1024.0; // Arduino Uno has a 10-bit ADC (0-1023)
const float TMP36_OFFSET    = 0.5;    // TMP36 outputs 500 mV at 0 degrees C

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
  // ---- Step 1: Read the raw analog value from the TMP36 sensor ----
  // analogRead() returns a value between 0 and 1023
  int rawValue = analogRead(TMP36_PIN);

  // ---- Step 2: Convert the raw ADC value into a voltage ----
  // voltage = (rawValue / max ADC steps) * reference voltage
  float voltage = (rawValue / ADC_RESOLUTION) * VOLTAGE_REF;

  // ---- Step 3: Convert voltage into temperature in Celsius ----
  // The TMP36 outputs 500 mV (0.5V) at 0 degrees C and then adds
  // 10 mV (0.01V) for every 1 degree Celsius above that, so we
  // subtract the offset before multiplying by 100.
  float temperatureC = (voltage - TMP36_OFFSET) * 100.0;

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
