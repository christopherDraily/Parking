#include "parking.h"
#include "Arduino.h"

void miseEnMarche(int tourSaisie, int rotation) {
  int tour = 0; //initialisation de la variable tour à 0
  int i = 0;  //initialisation de la variable i à 0

  do
  {
    switch (rotation) {   //cas rotation sens anti-horaire
      case 0:
        sequence1();        // appel de la fonction sequence1
        sequence2();       // appel de la fonction sequence2
        sequence3();      // appel de la fonction sequence3
        sequence4();     // appel de la fonction sequence4
        tour = tour + 1; // affectation a tour de tour +1
        break;

      case 1:   //cas rotation sens horaire
        sequence1();        // appel de la fonction sequence1
        sequence4();       // appel de la fonction sequence4
        sequence3();      // appel de la fonction sequence3
        sequence2();     // appel de la fonction sequence2
        tour = tour + 1; // affectation a tour de tour +1
        break;
    }
  } while (tour < (tourSaisie * 12));
}
int chrono(int chronoSeconde)
{
  static unsigned long premierAppel= 0;                    //savoir si il s'agit du premier appel
  static unsigned long tempPasse;                        //variable statique qui contiendra le temps ecoule
  unsigned long tempPresent;
  if (premierAppel==0){ // test si premier appel est egale a 0 
    tempPasse=millis(); // affectation de millis a la variable tempPasse
    premierAppel=1; // affectation de la valeur 1 a premierAppel 
    return 0; // retourne 0
  }
  tempPresent=millis();
  if ((tempPresent-tempPasse) >=(chronoSeconde*1000)){ // test si l'ecart entre temps present et temp passe est superieur ou egale a la variable chronos *1000 
    premierAppel = 0; //affectation de 0 a la variable premierAppel
    return 1;  // retourne 1
  }
  else { // sinon faire ...
    return 0; // retourne 0
  }
}

void sequence1(void) {
  digitalWrite(PAS1, HIGH);     // BROCHE active
  digitalWrite(PAS2, LOW);     // BROCHE inactive
  digitalWrite(PAS3, LOW);    // BROCHE inactive
  digitalWrite(PAS4, HIGH);  // BROCHE active
  delay(21);          // delay de  S
}
void sequence2(void) {
  digitalWrite(PAS1, HIGH);   // BROCHE active
  digitalWrite(PAS2, LOW);   // BROCHE inactive
  digitalWrite(PAS3, HIGH); // BROCHE active
  digitalWrite(PAS4, LOW); // BROCHE inactive
  delay(21);    // delay de  S
}
void sequence3(void) {
  digitalWrite(PAS1, LOW);    // BROCHE inactive
  digitalWrite(PAS2, HIGH);  // BROCHE active
  digitalWrite(PAS3, HIGH); // BROCHE active
  digitalWrite(PAS4, LOW); // BROCHE inactive
  delay(21);      // delay de  S
}
void sequence4(void) {

  digitalWrite(PAS1, LOW);        // BROCHE inactive
  digitalWrite(PAS2, HIGH);      // BROCHE active
  digitalWrite(PAS3, LOW);      // BROCHE inactive
  digitalWrite(PAS4, HIGH);    // BROCHE active
  delay(21); // delay de  S
}
