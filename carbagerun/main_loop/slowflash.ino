#include "Arduino.h"

void slowflash(int* pins) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(pins[i], HIGH);
  }
  delay(500); // Vertraagde flash tijd
  for (int i = 0; i < 8; i++) {
    digitalWrite(pins[i], LOW);
  }
  delay(250); // Vertraagde flash tijd
}
