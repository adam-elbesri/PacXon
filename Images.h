
#ifndef _IMAGES_H
#define _IMAGES_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstring>
using namespace sf;
using namespace std;

class Images {
private:
    string fond;
    string pacman;
    string* fantomes;
    string* bonus;

public:
    int ts;
    Images ();
    Images (const string &folder);
    Texture t1,t2,t3,t4,t5,t31,t32,t33,win;
    Music s1,s3,neww;
    SoundBuffer buffer,buffer1;
    Sound sound,sound1;
    Font font;
    Text text;
    Text vie,score,cases,cases1;
    Sprite sTile,
    sGameover, sEnemy, sPacman, sFleur;
    void afficherCase();
};

#endif // _IMAGES_H
