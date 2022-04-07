
#include "Grille.h"
#include <iostream>
using namespace std;

// Grille ------------
Grille::Grille () {
nbcases=0;
    for( unsigned int y = 0; (y < 25); y++ ) {
        for( unsigned int x = 0; (x < 40); x++ ) {
            if ((y == 0)||(x == 0)||(y == 25-1)||(x == 40 -1))
                cellules[y][x] = 1;
            else
                cellules[y][x] = 0;
    }}
}

Grille::Grille (const int &dimensionx, const int &dimensiony) {
    unsigned int dimx = dimensionx;
    unsigned int dimy = dimensiony;
    for( unsigned int y = 0; (y < dimy); y++ ) {
        for( unsigned int x = 0; (x < dimx); x++ ) {
            if ((y == 0)||(x == 0)||(y == dimy-1)||(x == dimx -1))
                cellules[y][x] = 1;
            else
                cellules[y][x] = 0;
    }}

}

// compte le nombre de case déjà remplies
    void Grille::compter()
{
    int nb=0;
     for( unsigned int y = 0; (y < 25); y++ ) {
        for( unsigned int x = 0; (x < 40); x++ ) {
                if (cellules[y][x]==1)nb++;}}
                nbcases=nb;
}

