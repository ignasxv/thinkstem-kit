void on(int pin)
{
    pinMode(pin, OUTPUT);    // Set the pin as an output
    analogWrite(pin, 250); // Turn on the pin
}

void dim(int pin, int delayTime = 10) {
    // pinMode(pin, OUTPUT);
  
    // Fade up
    for (int level = 0; level <= 255; level++) {
      analogWrite(pin, level);
      delay(delayTime);
    }
  
    // Fade down
    for (int level = 255; level >= 0; level--) {
      analogWrite(pin, level);
      delay(delayTime);
    }
  }

void off(int pin)
{
    pinMode(pin, OUTPUT);   // Set the pin as an output
    digitalWrite(pin, LOW); // Turn off the pin
}

void read(int pin){
    pinMode(pin, INPUT);          // Set the pin as an input
    int value = digitalRead(pin); // Read the value from the pin
    return value;                 // Return the value
}