// Digit segment map (a-b-c-d-e-f-g), common cathode assumed
const byte digitSegments[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
  };
  

void sevenSegmentSetup() {
  // Set segment pins as outputs
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void displayDigit(int num) {
  if (num < 0 || num > 9) return; // Ignore invalid input

  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digitSegments[num][i]);
  }
}


void displaySegment(char c) {
    // turn everything off
    for (int i = 0; i < 7; i++) {
      digitalWrite(segmentPins[i], LOW);
    }
  
    // normalize to lowercase
    c = tolower(c);
  
    // map letter → segment index
    int idx = -1;
    switch (c) {
      case 'a': idx = 0; break;
      case 'b': idx = 1; break;
      case 'c': idx = 2; break;
      case 'd': idx = 3; break;
      case 'e': idx = 4; break;
      case 'f': idx = 5; break;
      case 'g': idx = 6; break;
      default:  return;  // invalid → do nothing
    }
  
    // light that segment
    digitalWrite(segmentPins[idx], HIGH);
  }
  

  /**
   * I decided to Overload for C-string literal, to allow usage of both single quotes ('') and double quotes ("") 
   */
  void displaySegment(const char* s) {
    if (s && s[0] != '\0') {
      displaySegment(s[0]);
    }
  }

  void loopSegments(int delayTime) {
    for (int i = 0; i < 7; i++) {
      displaySegment(segmentLabels[i]);
      delay(delayTime);
    }   

  }

void segmentCount(int from, int to, int delayTime) {
    for (int i = from; i <= to; i++) {
      displayDigit(i);
      delay(delayTime);
    }
}
  
void segmentCount() {
    segmentCount(0, 9, 1000);
}

void segmentCount(int delayTime) {
    segmentCount(0, 9, delayTime);
}
