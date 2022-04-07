#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "Pacman.h"
#include <time.h>
#include <cstdlib>
using namespace sf;


Pacman::Pacman() {

    x = y = dx=dy=0;
    Nb_vies=3;
}

// Gère les déplacements de Pacman avec ls touches du clavier;

void Pacman::deplacer()
{

        if ((Keyboard::isKeyPressed(Keyboard::Left))&&(dx !=1)) {dx=-1;dy=0;};
        if ((Keyboard::isKeyPressed(Keyboard::Right))&&(dx !=-1))  {dx=1;dy=0;};
        if ((Keyboard::isKeyPressed(Keyboard::Up))&&(dy != 1))  {dx=0;dy=-1;};
        if ((Keyboard::isKeyPressed(Keyboard::Down))&&(dy != -1))  {dx=0;dy=1;};
}

//déplacement que dans la grille possible
void Pacman::deplacer2(Grille &grille)
{
         x+=dx;
         y+=dy;
         if (x<0) x=0;
         if (x>40-1) x=40-1;
         if (y<0) y=0;
         if (y>25-1) y=25-1;
         if (grille.cellules[y][x]==0) grille.cellules[y][x]=2;// remplir les case ou le pacman bouge
}
// fonction de retraite
void Pacman::fuite(Grille &grille)
{
    for (int i=1;i<25-1;i++)
                 for (int j=1;j<40-1;j++)
                   if(grille.cellules[i][j]==2) grille.cellules[i][j]=0;
                    x=0;y=0;

}
