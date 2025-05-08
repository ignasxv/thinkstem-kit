# ThinkSTEM Programming Kit

A hands-on kit for high school students to learn programming through interactive modules combining hardware and software.

## Learning Objectives

- Understand basic programming concepts (variables, loops, conditionals)
- Apply logic to control hardware (LEDs, sensors, motors)
- Build end-to-end projects integrating code and electronics
- Develop problem-solving and debugging skills

## Kit Components

- Microcontroller board (e.g., Arduino Uno)
- Breadboard and jumper wires
- LEDs and resistors
- Sensors (light, temperature)
- Outputs (buzzers, motors)
- Servo motors
- USB cable and power supply
- Instruction manual and software

## Curriculum Modules

- TBD

## Schedule

- TBD

## Resources

- Sample code library
- Troubleshooting guide
- Online reference materials

## Repository Structure

```
thinkstem-kit/
├── thinkstem-kit.ino    // Main Arduino sketch
├── 7-segment.ino        // Seven-segment display helper functions
└── README.md            // Project documentation
```

# thinkstem engineering kit

An Arduino-based kit to introduce programming and electronics concepts to middle and high school students with minimal hardware setup required. (plug and play)

# Features

- Semi-assembled hardware components for quick prototyping
- Custom Arduino functions to simplify interaction with a seven-segment display

## Seven-Segment Display Module

The `7-segment.ino` helper file provides the following functions:

### `void sevenSegmentSetup()`

Initializes all seven segment pins (A–G) as outputs and turns them off. Must be called in `setup()` before any display functions.

### `void displayDigit(int num)`

Lights up the segments corresponding to the digit `num` (0–9) on a common-cathode display.

- **Parameters**: `int num` — Digit to display (0–9).

### `void displaySegment(char c)`

Lights a single segment identified by the character `c` (`'a'`–`'g'` or `'A'`–`'G'`).

- **Parameters**: `char c` — Segment label.

### `void displaySegment(const char* s)`

Overloaded version accepting a C-string (e.g. `"a"`). Uses only the first character.

- **Parameters**: `const char* s` — String whose first character indicates the segment.

### `void loopSegments(int delayTime)`

Cycles through all seven segments in order (a–g), lighting each for `delayTime` milliseconds.

- **Parameters**: `int delayTime` — Delay in milliseconds between segments.

### `void segmentCount(int from, int to, int delayTime)`

Displays a sequence of digits from `from` to `to`, pausing `delayTime` milliseconds between each.

- **Parameters**:

  - `int from` — Starting digit (0–9)
  - `int to` — Ending digit (0–9)
  - `int delayTime` — Delay in milliseconds

### Overloaded `segmentCount()` Variants

- `segmentCount()` — Counts 0 through 9 with a default 1000 ms delay.
- `segmentCount(int delayTime)` — Counts 0 through 9 with custom delay.

## Main Sketch (`thinkstem-kit.ino`)

Includes and uses the seven-segment helper:

```cpp
#include <ctype.h>

// Segment pin mapping: A→8, B→9, C→12, D→11, E→10, F→7, G→6
const int segmentPins[7] = {8, 9, 12, 11, 10, 7, 6};
const char segmentLabels[7] = {'a','b','c','d','e','f','g'};

void setup() {
  sevenSegmentSetup();
}

void loop() {
  loopSegments(300);
}
```

This setup cycles through segments a–g, each lit for 300 ms.

## Getting Started

1. Open `thinkstem-kit.ino` in the Arduino IDE.
2. Ensure `7-segment.ino` is in the same folder.
3. Customize pin mappings or display routines as needed.
4. Upload to your Arduino and watch the display in action.

## Next Steps

- Add support for a decimal point (DP) segment.
- Implement multi-digit display via multiplexing.
- Create curriculum exercises around segment control.
