#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct jeton {
    char lettre;
    int points;               
} t_jeton;

typedef struct joueur{
    int existe ;
    char pseudo[20];
    t_jeton jeton[7];
    int points;
}t_joueurs;

t_joueurs player[4];  // structure globale des joueurs
int nbreJ;    // variable globale (nombre de joueurs)

void credits();
void aide();
void commencer();  //demande le nom de chaque joueur et affecte le nombre de joueur à nbreJ, affecte à player le pseudo des joueurs et affecte à player si le joueur existe oui ou non
void sauvegarde();
void reprendre();
void score();

t_jeton pioche[102];
void melangeLaPioche();   // initialise et melange la pioche 
int position = 0;  // variable globale décrivant l'avancement dans la pioche (rappel: la pioche est déjà mélangée pour tte la partie)
int FIN=0; // variable globale décrivant si la derniere lettre a été pioché. 

int tour; // variable globale designant quel joueur joue (1,2,3 ou 4)
void lancer();   //  crée le chevalet pour chaque joueur, affiche le chevalet de chaque joueur et tire aleatoirement le joueur qui commence.

void piocheLettres(); // lorsque un joueur a déposé un mot sur la planche, le joueur pioche de nouveaux jetons. et affiche sa nouvelle pioche

void afficheChevalet();
int cestLaFin();
void leGagnantEst();
void afficheChevalet();
void leGagnantEst();


void lancer();
void deposePremierMot();

int verifieDico(char unmot[20], int L);
void affichePlanche();
void deposeMot();
