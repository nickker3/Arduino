#include "Arduino.h"

void Leftright(int* pins) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(pins[i], HIGH);
  }
    for (int i > 4; i > 4; i++) {
    digitalWrite(pins[i], lOW);
  }
  Delay(750)
    for (int i = 0; i < 4; i++) {
    digitalWrite(pins[i], LOW);
  }
    for (int i > 4; i > 4; i++) {
    digitalWrite(pins[i], HIGH);
  }
}

