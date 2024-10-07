#include "Looplamp.h"

int R0 = 0;
int R1 = 1;
int R2 = 2;
int R3 = 3;
int R4 = 4;
int R5 = 5;
int R6 = 6;
int R7 = 7;
int TEST = 13;

int LOOPLAMP = 21;

int pins[] = {R0, R1, R2, R3, R4, R5, R6, R7};

// Instantieer een object van de Looplamp klasse
Looplamp looplamp(TEST, pins);

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize output's
  pinMode(TEST, OUTPUT);
  for(int i = 0; i < 8; i++) {
    pinMode(pins[i], OUTPUT);
  }

  pinMode(LOOPLAMP, INPUT);
}

void loop() {
  looplamp.runLooplamp();
}
