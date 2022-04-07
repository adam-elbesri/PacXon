#ifndef NIVEAU_H
#define NIVEAU_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Grille.h"
#include "Pacman.h"
#include "Fantome.h"
#include "Bonus.h"
#include "Images.h"
#include "Menu.h"
using namespace sf;

class Niveau {
public:
    unsigned int id;
    int ts;
    int NBR_VIES;
    Grille grille;
    bool Game;
    Pacman pacman;
    unsigned int NBR_FANTOMES;
    Fantome* fantomes;
    Fantome tabFantomes[10];
    Sprite sprite;
    Images im;
    Niveau();
    Niveau(unsigned int id, unsigned int NBR_FANTOMES, Fantome* fantomes);
    void boucle();
    void afficher(Grille &grille);
    void deplacement_fantomes();
    void remplirGrille();
    void cellules_adjacentes(int y, int x);
    void draw(RenderWindow &window);
    void fuite();
    int testFin();
};

#endif // NIVEAU_H
