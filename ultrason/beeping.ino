#define buzzer 8

void setup() {
  pinMode(buzzer, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    setupUltrasonic();
    Serial.begin(9600);

    

    
}

void loop() {
  long distance = readUltrasonic();
if (distance < 5) {
  digitalWrite(buzzer, 1);
}
else {
  digitalWrite(buzzer, 0);
}
     Serial.println(distance);
     delay(20);
}