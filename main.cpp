#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Niveau.h"
#include <time.h>
#include <iostream>
using namespace std;
using namespace sf;
// 126 case remplir de base 950 toutes = 950 - 126 = 824
int ts = 18; //tile size
#include <iostream>
#include "Menu.h"
void jeu()
{
    srand(time(0));
    err().rdbuf(NULL); // enelve lerreur de merde
    RenderWindow window(VideoMode(40*ts, 27*ts), "PACXON!"); // ouverture dune fenetre
    window.setFramerateLimit(60); // limite de fps
    Images im;
    Sprite  sGameover(im.t2), sEnemy(im.t3),sEnemy1(im.t31), sEnemy2(im.t32), sEnemy3(im.t33); // generation de sprite
    sGameover.setPosition(100,100); // position game over
    sEnemy.setOrigin(20,20);
    sEnemy1.setOrigin(20,20);
    sEnemy2.setOrigin(20,20);
    sEnemy3.setOrigin(20,20);     // position des enemmi
    Niveau Niveau0;
    float timer=0, delay=0.07;
    Clock clock;
    im.neww.play();
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }
        Niveau0.pacman.deplacer();  // deplacer pacman
        if (!Niveau0.Game) continue;
        if (timer>delay)
        {
            Niveau0.pacman.deplacer2(Niveau0.grille);
            Niveau0.grille.compter();
            timer=0;
        }

////////////////draw///////////////
                window.clear();

Niveau0.fuite();
Niveau0.deplacement_fantomes();
Niveau0.remplirGrille();
Niveau0.draw(window);


    for (unsigned int i=0; i<Niveau0.NBR_FANTOMES; i++) {
           unsigned int t = Niveau0.tabFantomes[i].type;
           // affichage fantome
           if (t == 0) {
                sEnemy.setPosition(Niveau0.tabFantomes[i].x,Niveau0.tabFantomes[i].y);
                window.draw(sEnemy);
           } if (t == 1) {
                sEnemy1.setPosition(Niveau0.tabFantomes[i].x,Niveau0.tabFantomes[i].y);
                window.draw(sEnemy1);
           } if (t == 2) {
                sEnemy2.setPosition(Niveau0.tabFantomes[i].x,Niveau0.tabFantomes[i].y);
                window.draw(sEnemy2);
           } if (t == 3) {
                sEnemy3.setPosition(Niveau0.tabFantomes[i].x,Niveau0.tabFantomes[i].y);
                window.draw(sEnemy3);
           }

       }
       window.display();
    }




}



void menu(RenderWindow &window)

{
    Texture t1;
    if(!t1.loadFromFile("images/paxcon.jpg")) cout<<"erreur";
    Sprite sFond(t1);
	Menu menu(window.getSize().x, window.getSize().y);//
	while (window.isOpen())
	{
		Event event;
		SoundBuffer buffer;
		buffer.loadFromFile("sounds/menu.wav");
		Sound sound;
        sound.setBuffer(buffer);
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Up:
					menu.MoveUp();
					break;

				case Keyboard::Down:
					menu.MoveDown();
					break;

				case Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
                        sound.play();
					      window.close();
					    jeu();

						cout << "Jouer a été appuyé" << endl;
						break;
					case 1:

						cout << "Prochainement" << endl;

						break;
					case 2:
					    sound.play();
						window.close();
						break;
					}

					break;
				}

				break;
			case Event::Closed:
				window.close();

				break;

			}
		}
		window.clear();
		window.draw(sFond);
		menu.draw(window);
		window.display();
	}
}

int main ()
{
    srand(time(0));
    err().rdbuf(NULL); // Enleve une erreur console
    RenderWindow window(VideoMode(40*ts, 27*ts), "PACXON!"); // ouverture dune fenetre
    window.setFramerateLimit(60); // limite de fps
    menu(window);
    return 0;
}




