void buzzerSetup()
{
    pinMode(buzzerPin, OUTPUT);   // Set the buzzer pin as an output
    digitalWrite(buzzerPin, LOW); // Initialize the buzzer to be off
}

void buzz(int intesityPercent)
{
    int pwmValue = map(constrain(intesityPercent, 0, 100), 0, 100, 0, 255);
    analogWrite(buzzerPin, pwmValue);
}
void unbuzz(){
  buzz(0);
}
