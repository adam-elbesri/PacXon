
#ifndef PACMAN_H
#define PACMAN_H

#include "Grille.h"




class Pacman {
public:
     int x, y,Nb_vies;
float dx, dy;
    Pacman();
    void deplacer();
    void deplacer2(Grille &grille);
    void fuite(Grille &grille);
};

#endif // PACMAN_H
