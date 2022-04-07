#include <iostream>
#include "Fantome.h"
#include <cstdlib>
#include <time.h>
using namespace std;
Fantome::Fantome() {
     type = rand()%3;
     ts=18;
     y = x=300;
     dy = 4-rand()%8; // direction aleatoire des fantomes
     dx = 4-rand()%8;
     while(dy==0 || dx==0)
     {
        dy = 4-rand()%8;
        dx = 4-rand()%8;
     }

    vitesse = 1.0;
    visible = true;
}

Fantome::Fantome(unsigned int type) {
    type = type;
    y = 0;
    x=0;
     dy = 1.0;
     dx = 1.0;
    vitesse = 1.0;
    visible = (type != 1);

}
//deplacement du fantome
void Fantome::deplacement(Grille &grille) {
    x+=dx; if (grille.cellules[y/ts][x/ts]==1) {dx=-dx; x+=dx;}
    y+=dy; if (grille.cellules[y/ts][x/ts]==1) {dy=-dy; y+=dy;}
}


