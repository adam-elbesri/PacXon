
#ifndef _GRILLE_H
#define _GRILLE_H

#include "Images.h"



class Grille {

public:
int nbcases;
    int cellules[25][40];


    Grille ();
    Grille (const int &dimensionx, const int &dimensiony);

void compter();


};

#endif // _GRILLE_H
