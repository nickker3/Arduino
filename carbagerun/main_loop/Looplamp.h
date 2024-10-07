#ifndef LOOPLAMP_H
#define LOOPLAMP_H

class Looplamp {
  public:
    Looplamp(int* pins);  // Constructor
    void runLooplamp();  // Declaratie van de methode
  private:
    int* _pins;
};

#endif
