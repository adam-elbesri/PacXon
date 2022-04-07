
#include "Images.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
// Images ------------
Images::Images () {
    ts=18;
    fond = "../data/img/default/bg.png";
    pacman = "../data/img/default/pacman.png";
     if(!t1.loadFromFile("images/tiles.png")) cout<<"erreur";
    if(!t2.loadFromFile("./images/gameover.png"))cout<<"erreur";;
    t3.loadFromFile("./images/pinky.png");
    t4.loadFromFile("./images/pacman.png");
    t5.loadFromFile("./images/bg.png");
    t31.loadFromFile("./images/inky.png");
    t32.loadFromFile("./images/blinky.png");
    t33.loadFromFile("/images/clyde.png");
    win.loadFromFile("./images/win.png");
    score.setFont(font);
    score.setPosition(14*ts,25*ts);
    score.setFillColor(Color::White);
    score.setCharacterSize(26);
    score.setStyle(Text::Bold);
    cases.setFillColor(Color::Green);
    cases.setFont(font);
    cases.setCharacterSize(26);
    cases.setStyle(Text::Bold);
    cases.setPosition(29.5*ts,25*ts);
    cases1.setString("Progression       /675 cases");
    cases1.setFont(font);
    cases1.setCharacterSize(26);
    cases1.setStyle(Text::Bold);
    cases1.setPosition(21*ts,25*ts);
    cases1.setFillColor(Color::Green);
    buffer.loadFromFile("sounds/bruh.wav");
    buffer1.loadFromFile("sounds/moving.wav");
    sound1.setBuffer(buffer1);
    sound1.setVolume(20);
    sound.setBuffer(buffer);
    text.setString("VOUS AVEZ REUSSI LE REMPLISSAGE DE LA GRILLE ! ");
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(Color::White);
    text.setPosition(20,160);
    text.setStyle(Text::Bold);
    vie.setString("Nombres de vies : ");
    vie.setFont(font);
    vie.setCharacterSize(26);
    vie.setFillColor(Color::White);
    vie.setPosition(1*ts,25*ts);
    vie.setStyle(Text::Bold);
    if(!font.loadFromFile("images/ArialCE.ttf"))cout<<"error";
    s1.openFromFile("sounds/boo.wav");
    s3.openFromFile("sounds/win.wav");
    neww.openFromFile("sounds/new.wav");
}

Images::Images (const string &pack) {
    fond = "../data/img/"+ pack+ "/bg.png";
    pacman = "../data/img/"+ pack+ "/pacman.png";
    /*
    */
}

// A FAIRE : getFond(), getPacman()...

void Images::afficherCase() {
}
