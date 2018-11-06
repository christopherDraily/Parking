#include "parking.h"

int compteur = 0;

void setup() {
  Serial1.begin(1200);
  pinMode(PAS1, OUTPUT);  // declaration de la broche 10 en sortie
  pinMode(PAS2, OUTPUT);  // declaration de la broche 11 en sortie
  pinMode(PAS3, OUTPUT);  // declaration de la broche 12 en sortie
  pinMode(PAS4, OUTPUT);  // declaration de la broche 13 en sortie
  pinMode(BOUCLEAMONT, INPUT); // declaration en entrée de la broche 22
  pinMode(BOUCLEAVAL, INPUT); // declaration en entrée de la broche 24
  pinMode(VALIDATION, INPUT); // declaration en entrée de la broche 26

}


void loop() {

  if (digitalRead(BOUCLEAMONT) == 1 && digitalRead(BOUCLEAVAL) == 0)
  {
    delay(20);
    if (digitalRead(VALIDATION) == 1) {
      delay(20);
      miseEnMarche(2, OUVRIR); // appel de la fonction miseEnMarche du moteur avec en parametres 2 tours dans le sens horaire
      while (digitalRead(BOUCLEAMONT) == 1 && digitalRead(BOUCLEAVAL) == 0 && chrono(30) == 0); // tant que boucle amont est active et que boucle aval est inactive et que la temporisation  retourne 0
      delay(20);                                                                //evite les rebonds de l'interrupteur
      if (digitalRead(BOUCLEAMONT) == 0 || digitalRead(BOUCLEAVAL) == 1) { // si boucle amont est inactive et boucle aval est active
        if (digitalRead(BOUCLEAMONT) == 1) {
          while (digitalRead(BOUCLEAMONT) == 1 || digitalRead(BOUCLEAVAL) == 1) ; // tant que boucle a mont est active et boucle aval aussi
          compteur = compteur + 1; //incrementation de la variable compteur
          Serial1.print("le nombre de voiture dans le parking est de: ");
          Serial1.println(compteur);
        }
      }
      miseEnMarche(2, FERMER); // fermeture de la barriere
    }
  }
  if (( digitalRead(BOUCLEAVAL) == 1) && (digitalRead(BOUCLEAMONT) == 0))
  {
    miseEnMarche(2, OUVRIR); // appel de la fonction miseEnMarche du moteur avec en parametres 2 tours dans le sens horaire
    while (digitalRead(BOUCLEAVAL) == 1 &&  digitalRead(BOUCLEAMONT) == 0);
    if ( digitalRead(BOUCLEAMONT) == 1 ||  digitalRead(BOUCLEAVAL) == 1)
    {
      while ( digitalRead(BOUCLEAMONT) == 1 ||  digitalRead(BOUCLEAVAL) == 1);
      compteur = compteur - 1; //decrementation de la variable compteur
      Serial1.print("le nombre de voiture dans le parking est de: ");
      Serial1.println(compteur);
    }
    miseEnMarche(2, FERMER); // fermeture de la barriere
  }
}
