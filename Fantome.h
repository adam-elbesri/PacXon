#ifndef FANTOME_H
#define FANTOME_H


#include "Grille.h"



class Fantome {
private:

    float vitesse;
    bool visible;

public:
    unsigned int type;
    unsigned int x, y,ts;
    float dx, dy;
    Fantome();
    Fantome(unsigned int type);

   void deplacement(Grille &grille);

};

#endif // FANTOME_H
