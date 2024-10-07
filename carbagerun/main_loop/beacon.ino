#include "Arduino.h"

void beacon(int* pins) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(pins[i], HIGH);
  }
  delay(1000); // Aan-tijd voor beacon
  for (int i = 0; i < 8; i++) {
    digitalWrite(pins[i], LOW);
  }
  delay(40); // Uit-tijd voor beacon
}
