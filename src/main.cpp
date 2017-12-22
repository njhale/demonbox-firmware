#include <Arduino.h>

const int LEFT_EYE_LED_PIN = 10;


/**
 * pulseLight
 */
void pulseLight(int pin, int interval) {

  bool inflect = false;
  int output = 0;

  for (int i = 0; i < 512; i++) {
    // Write to analog out on the pin
    analogWrite(pin, output);

    // Count up until inflection point
    if (output == 255) {
      inflect = true;
    } else if (output == 0) {
      inflect = false;
    }

    if (inflect) {
      output--;
    } else {
      output++;
    }

    // Wait for interval
    delay(interval);

  }

}

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);

  // Set high output pins
  Serial.println("Setting high output pins...");
  pinMode(LEFT_EYE_LED_PIN, HIGH);
  Serial.println("High output pins set");

}

void loop() {
  // Call pulse light
  Serial.println("Pulsing light...");
  pulseLight(LEFT_EYE_LED_PIN, 10);
  Serial.println("Light pulsed");

}
