/**
 * sonarSetup()
 *   Configure the pins for the HC-SR04 ultrasonic distance sensor.
 *
 * @param tPin  Arduino pin connected to the sensor's TRIG pin
 * @param ePin  Arduino pin connected to the sensor's ECHO pin
 */
void sonarSetup(int tPin, int ePin) {
  trigPin = tPin;
  echoPin = ePin;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
}

/**
 * readDistanceCM()
 *   Sends a 10µs pulse on TRIG, measures the echo duration,
 *   and converts it to distance in centimeters.
 *
 * @return Distance in cm, or -1 if no echo received within timeout.
 */
long readDistanceCM() {
  if (trigPin < 0 || echoPin < 0) {
    // Pins not initialized
    return -1;
  }

  // Trigger a 10µs HIGH pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo pulse duration, timeout after 30 ms
  long duration = pulseIn(echoPin, HIGH, 30000);
  if (duration <= 0) {
    // no echo (out of range or timeout)
    return -1;
  }

  // Convert to distance:
  // Sound speed ≈ 343 m/s → 29.1 µs per cm round-trip
  long distanceCm = duration / 29.1 / 2;
  return distanceCm;
}
