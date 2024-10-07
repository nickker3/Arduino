// Definitie van de klasse Looplamp
class Looplamp {
  public:
    void runLooplamp();  // Declaratie van de methode
};

// Implementatie van de methode runLooplamp buiten de klasse
void Looplamp::runLooplamp() {
  digitalWrite(TEST, HIGH);  
  delay(100);
  digitalWrite(R0, HIGH);
  delay(100);
  digitalWrite(R1, HIGH);
  delay(100);
  digitalWrite(R2, HIGH);
  delay(100);
  digitalWrite(R3, HIGH);
  delay(100);
  digitalWrite(R4, HIGH);                  
  delay(100);
  digitalWrite(R5, HIGH);
  delay(100);
  digitalWrite(R6, HIGH);
  delay(100);
  digitalWrite(R7, HIGH);

  digitalWrite(TEST, LOW);  
  delay(100);
  digitalWrite(R0, LOW);
  delay(100);
  digitalWrite(R1, LOW);
  delay(100);
  digitalWrite(R2, LOW);
  delay(100);
  digitalWrite(R3, LOW);
  delay(100);
  digitalWrite(R4, LOW);                     
  delay(100);
  digitalWrite(R5, LOW);
  delay(100);
  digitalWrite(R6, LOW);
  delay(100);
  digitalWrite(R7, LOW);
}