#include "Looplamp.h"

// Declaratie van de flashLamps, slowflash en beacon functies die in FlashLamp.ino, slowflash.ino en beacon.ino staan
void flashLamps(int* pins);
void slowflash(int* pins);
void beacon(int* pins);

char data[10];  // Vergroot de grootte van data om een string te kunnen opslaan
int dataIndex = 0; // Index voor het bijhouden van de positie in de data array

int R0 = 53;
int R1 = 51;
int R2 = 49;
int R3 = 47;
int R4 = 45;
int R5 = 43;
int R6 = 41;
int R7 = 39;

int LOOPLAMP = 7;  // Input pin voor looplamp modus
int FLASHLAMP = 6; // Input pin voor flash modus
int SLOWFLASH = 5; // Input pin voor slow flash modus
int BEACON = 4; // Input pin voor beacon modus

int pins[] = {R0, R1, R2, R3, R4, R5, R6, R7};

// Instantieer een object van de Looplamp klasse
Looplamp looplamp(pins);

// Declareer de status variabelen
int looplampStatus = HIGH; // Begin met de pin in de HIGH status
int flashlampStatus = HIGH; // Begin met de pin in de HIGH status
int slowflashStatus = HIGH; // Begin met de pin in de HIGH status
int beaconStatus = HIGH; // Begin met de pin in de HIGH status
int lampmodus = 0; // Begin met lampmodus uitgeschakeld

// De setup functie wordt één keer uitgevoerd wanneer je de Arduino reset of aanzet
void setup() {
  Serial.begin(9600); // Gebruik de standaard seriële poort voor debugging
  Serial1.begin(9600); // Gebruik Serial1 voor de Bluetooth-module
  // Initialiseer outputs
  for (int i = 0; i < 8; i++) {
    pinMode(pins[i], OUTPUT);
  }

  pinMode(LOOPLAMP, INPUT_PULLUP); // Stel de pin in als INPUT met interne pull-up weerstand
  pinMode(FLASHLAMP, INPUT_PULLUP); // Stel de pin in als INPUT met interne pull-up weerstand
  pinMode(SLOWFLASH, INPUT_PULLUP); // Stel de pin in als INPUT met interne pull-up weerstand
  pinMode(BEACON, INPUT_PULLUP); // Stel de pin in als INPUT met interne pull-up weerstand
}

void loop() {
  looplampStatus = digitalRead(LOOPLAMP); // Lees de status van de pin
  flashlampStatus = digitalRead(FLASHLAMP); // Lees de status van de flash pin
  slowflashStatus = digitalRead(SLOWFLASH); // Lees de status van de slowflash pin
  beaconStatus = digitalRead(BEACON); // Lees de status van de beacon pin

  while (Serial1.available() > 0) { // Verwerk data alleen wanneer je data ontvangt:
    char incomingByte = Serial1.read();  // Lees de binnenkomende data en sla deze op in data
    if (incomingByte == '\n' || incomingByte == '\r') {  // Controleer op newline of carriage return teken als einde van commando
      if (dataIndex > 0) {  // Verwerk alleen als er data in de buffer staat
        data[dataIndex] = '\0'; // Sluit de string af
        Serial.print("Received via Bluetooth: "); // Voeg deze regel toe voor debugging
        Serial.println(data); // Print waarde binnen data in seriële monitor
        if (strcmp(data, "FF1") == 0) {    // Vergelijk de string met "FF1"
          lampmodus = 2;
        } else if (strcmp(data, "BC1") == 0) {  // Vergelijk de string met "BC1"
          lampmodus = 4;
        } else if (strcmp(data, "LL1") == 0) {  // Vergelijk de string met "LL1"
          lampmodus = 1;
        } else if (strcmp(data, "on") == 0) {   // Vergelijk de string met "on"
          lampmodus = 5; // Nieuwe modus voor alles aan
        } else if (strcmp(data, "off") == 0) {  // Vergelijk de string met "off"
          lampmodus = 6; // Nieuwe modus voor alles uit
        } else if (strcmp(data, "0") == 0) {
          lampmodus = 0;
        }
        dataIndex = 0;  // Reset dataIndex voor het volgende commando
      }
    } else {
      if (dataIndex < sizeof(data) - 1) {
        data[dataIndex++] = incomingByte; // Voeg incomingByte toe aan data
      }
    }
  }

  if (beaconStatus == LOW) {
    lampmodus = 4;
  } else if (slowflashStatus == LOW) {
    lampmodus = 3;
  } else if (flashlampStatus == LOW) {
    lampmodus = 2;
  } else if (looplampStatus == LOW) {
    lampmodus = 1;
  }

  switch (lampmodus) {
    case 5:
      for (int i = 0; i < 8; i++) {
        digitalWrite(pins[i], LOW);  // Zet alle lampen aan
      }
      break;
    case 6:
      for (int i = 0; i < 8; i++) {
        digitalWrite(pins[i], HIGH);  // Zet alle lampen uit
      }
      break;
    case 4:
      beacon(pins);
      break;
    case 3:
      slowflash(pins);
      break;
    case 2:
      flashLamps(pins);
      break;
    case 1:
      looplamp.runLooplamp();
      break;
    case 0:
      for (int i = 0; i < 8; i++) {
        digitalWrite(pins[i], LOW);  // Zet alle lampen uit in de default modus
      }
      break;
    default:
      // Optioneel: code om eventuele andere situaties te behandelen
      break;
  }
}
