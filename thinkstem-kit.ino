#include <ctype.h> // for tolower()

const int buzzerPin = 5; // Buzzer pin

// Segment pins
const int segmentPins[7] = {8, 9, 12, 11, 10, 7, 6}; // A, B, C, D, E, F, G
// segment labels
const char segmentLabels[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

// define and initialize the ultrasonic sensor
static int trigPin = 3;
static int echoPin = 4;

void setup()
{
    Serial.begin(115200); // Initialize serial communication
    sevenSegmentSetup(); // Call the setup function for the 7-segment display
    buzzerSetup();       // Call the setup function for the buzzer
    sonarSetup(trigPin, echoPin); // Call the setup function for the ultrasonic sensor
}

void loop(){
    // Serial.println(readDistanceCM()); // Print the distance to the serial monitor
    readDistanceCM();

}

