#define BOUCLEAMONT 22 // definition d'une constante pour la broche 22 qui est la boucle Amont
#define BOUCLEAVAL 24 // definition d'une constante pour la broche 24 qui est la boucle Aval
#define VALIDATION 26 // definition d'une constante pour la broche 26 qui est la boucle Aval
#define PAS1 10 // definition d'une consatnte pour la broche 10 qui est le pas 1 du moteur 
#define PAS2 11 // definition d'une consatnte pour la broche 11 qui est le pas 2 du moteur 
#define PAS3 12 // definition d'une consatnte pour la broche 12 qui est le pas 3 du moteur 
#define PAS4 13 // definition d'une consatnte pour la broche 13 qui est le pas 4 du moteur 
#define OUVRIR 1 // definition d'une constante pour l'ouverture 
#define FERMER 0 // definition d'une constante pour la fermeture




void miseEnMarche(int , int); // prototype de la fonction miseEnMarche qui permet de faire tourner le moteur dans les 2 sens
int chrono(int ); // fonction qui renvoit 1 au bout du temps passé en paramètre en seconde , sinon elle renvoit 0

void sequence1(void);  // prototype de la fonction sequence1 qui n'accepte aucun parametres et qui ne renvoit rien
void sequence2(void); // prototype de la fonction sequence2 qui n'accepte aucun parametres et qui ne renvoit rien
void sequence3(void); // prototype de la fonction sequence3 qui n'accepte aucun parametres et qui ne renvoit rien
void sequence4(void); // prototype de la fonction sequence4 qui n'accepte aucun parametres et qui ne renvoit rien
