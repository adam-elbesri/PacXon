========== PACXON ============


---- Inclure la bibliothèque graphique SFML :

1. Télécharger la bibliothèque SFML depuis le site officiel ( Version adaptée à CodeBlocks)
2. Dans "Build Options" du projet inclure les chemins vers les diffèrentes librairie de SFML (tutorial complet ici : https://www.sfml-dev.org/tutorials/2.5/start-cb-fr.php )



---- BUT DU JEU :

On controle Pacman sur une grille de 25*40 cases.
Le but du jeu est de traverser la grille en évitant les Fantomes qui se déplacent, pour remplir les cases et atteindre un certain pourcentage de remplissage.
Pacman possède trois vies, ont peut donc fauter 3 fois seulement.

Si on épuise toutes les vies la partie est perdue. Mais si on arrive à remplir la grille on gagne !



---- CONTROLES :

On utilise les flèches du clavier pour se déplacer.
La touché "échap" permet d'annuler le tracé que nous sommes entrain de faire si nous somme sur le point de perdre une vie.
