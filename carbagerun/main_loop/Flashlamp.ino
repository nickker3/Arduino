#include "Arduino.h"

void flashLamps(int* pins) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(pins[i], HIGH);
  }
  delay(25);
  for (int i = 0; i < 8; i++) {
    digitalWrite(pins[i], LOW);
  }
  delay(25);
}
