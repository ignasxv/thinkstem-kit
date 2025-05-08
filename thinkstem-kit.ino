#include <ctype.h> // for tolower()

const int buzzerPin = 5; // Buzzer pin

// Segment pins
const int segmentPins[7] = {8, 9, 12, 11, 10, 7, 6}; // A, B, C, D, E, F, G
// segment labels
const char segmentLabels[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

void setup()
{
    sevenSegmentSetup(); // Call the setup function for the 7-segment display
    buzzerSetup();       // Call the setup function for the buzzer
}

void loop(){
   for(int i=0; i < 10l; i++){
    displayDigit(i); // Display the digit on the 7-segment display
    buzz(10);
    delay(200);
    unbuzz(); // Turn off the buzzer
    delay(200);

   }
    unbuzz(); // Default delay time of 100 ms
}

