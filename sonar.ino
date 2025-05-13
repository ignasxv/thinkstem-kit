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
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;  // Convert to cm
  Serial.println(distance);
  return distance;
}
