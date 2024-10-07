#include "Arduino.h"
#include "Looplamp.h"

Looplamp::Looplamp(int* pins) {
  _pins = pins;
}

void Looplamp::runLooplamp() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(_pins[i], HIGH);
    delay(100);
  }
  
  for (int i = 0; i < 8; i++) {
    digitalWrite(_pins[i], LOW);
    delay(100);
  }
}
