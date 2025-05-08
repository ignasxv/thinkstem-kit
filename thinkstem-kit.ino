#include <ctype.h>  // for tolower()
 


void setup(){
    sevenSegmentSetup(); // Call the setup function for the 7-segment display 
}

void loop() {
    loopSegments(300); // Call the loopSegments function with a delay of 1000 milliseconds (1 second)
}
