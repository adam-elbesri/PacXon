#include <sstream>
#include "Niveau.h"
#include <iostream>
#include <cstdlib>
using namespace std;


Niveau::Niveau() {
    id = 0;
    ts=18;
    grille = Grille();
    pacman = Pacman();
    Game=true;
    NBR_FANTOMES = 5;
    NBR_VIES=3;
}

Niveau::Niveau(unsigned int id, unsigned int NBR_FANTOMES, Fantome* fantomes) {
    id = id;
    pacman = Pacman();
    NBR_FANTOMES = NBR_FANTOMES;
    fantomes = fantomes;
}

//deplacement des fantome
void Niveau :: deplacement_fantomes()
{
    for (unsigned int i=0;i<NBR_FANTOMES;i++)
            tabFantomes[i].deplacement(grille);
}

// annuler un tra en cours
void Niveau::fuite()
{
    if (Keyboard::isKeyPressed(Keyboard::Escape)) pacman.fuite(grille);
}


// fonction pour remplir une zone si il n'ya pas de fantome  l'intrieur

void Niveau ::cellules_adjacentes(int y,int x)  //
{
  if (grille.cellules[y][x]==0) grille.cellules[y][x]=-1;
  if (grille.cellules[y-1][x]==0) cellules_adjacentes(y-1,x);
  if (grille.cellules[y+1][x]==0) cellules_adjacentes(y+1,x);
  if (grille.cellules[y][x-1]==0) cellules_adjacentes(y,x-1);
  if (grille.cellules[y][x+1]==0) cellules_adjacentes(y,x+1);

}

// fonction de remplissage de la grille
void Niveau :: remplirGrille()
{

    if (grille.cellules[pacman.y][pacman.x]==1)
          {
           pacman.dx=0;
           pacman.dy=0;
           for (unsigned int i=0;i<NBR_FANTOMES;i++)
                cellules_adjacentes(tabFantomes[i].y/ts, tabFantomes[i].x/ts);
           for (unsigned int i=0;i<25;i++)
             for (int j=0;j<40;j++)
              if (grille.cellules[i][j]==-1)
                grille.cellules[i][j]=0;
                else
                grille.cellules[i][j]=1;
          }

        for (unsigned int i=0;i<NBR_FANTOMES;i++)
           if  (grille.cellules[tabFantomes[i].y/ts][tabFantomes[i].x/ts]==2)
            {
                for( unsigned int y = 0; (y < 25); y++ ) {
                    for( unsigned int x = 0; (x < 40); x++ ) {
                    if (grille.cellules[y][x]==2)
                            grille.cellules[y][x] = 0;}}
                            NBR_VIES--; pacman.x=pacman.y=0;im.sound.play();cout<<"touch";}//Game=false;
}


// fonction d'affichage
string IntToString(int value)
{
	//Uses a stringstream to format text, similar to std::cout,
	//but without printing anything on the screen.
	stringstream sstream;
	//Pass the value into the stringstream.
	sstream << value;
	//Get the contents as a std::string.
	return sstream.str();
}

void Niveau::draw(RenderWindow &window) {

Sprite sTile, sGameover, sPacman, sFond,sWin;
sWin .setTexture(im.win);
sWin.setPosition(40,00);//
Sprite sprite;
sTile.setTexture(im.t1);
sGameover.setTexture(im.t2);
sGameover.setPosition(100,100);
sPacman.setTexture(im.t4);
sFond.setTexture(im.t5);
window.draw(sFond);
window.draw(im.vie);
window.draw(im.score);


int CASES=grille.nbcases-126;
im.score.setString(IntToString(NBR_VIES));
im.cases.setString(IntToString(CASES));



     for (int i=0;i<25;i++)
            for (int j=0;j<40;j++)
            {
                if (grille.cellules[i][j]==0) continue;
                if (grille.cellules[i][j]==1) sTile.setTextureRect(IntRect( 0,0,ts,ts)); // case bleu remplie
                if (grille.cellules[i][j]==2) {im.sound1.play();    sTile.setTextureRect(IntRect(34,0,ts,ts));} //case rouge pendant remplissage
                sTile.setPosition(j*ts,i*ts);
                window.draw(sTile);
            }

sPacman.setPosition(pacman.x*ts,pacman.y*ts); // Position sprite pacman
window.draw(sPacman); // affichage pacman
//test fin de jeu
window.draw(im.cases1);
window.draw(im.cases);
if (grille.nbcases>800) // 674
       {
           cout<<grille.nbcases-126;
           Game=false;
           im.s3.play();

            window.draw(sWin);
       }

// test fin de jeu
if (NBR_VIES<0)
{   Game=false;
    window.draw(sGameover);
    im.s1.play();
}

}














