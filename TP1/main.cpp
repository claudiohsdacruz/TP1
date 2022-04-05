/************************************************************************************
* Auteur	: Claudio Cruz et Ramin	Amiri											*
* Nom		: main.cpp																*
* Date		: 03 avril 2022															*
* Description : La classe Game implémente Le jeu Snake en console où les flèches 	*
*		  servent  à déplacer le snake dans l’écran pour manger les pommes,			*
*		  mais attention de ne pas toucher les côté ou le snake lui-même. 			*
************************************************************************************/
#include <iostream>
#include <cassert>
#include <Windows.h>
#include "point.h"
#include "snake.h"
#include "apple.h"
using namespace std;

void main() {
	/*
	//Initialise la Game (initialise le booléen, les vies, le score, le Snake et la première pomme)
	
	Tant Que ce n’est pas gameOver
		Affiche le score
		Saisit la touche
		Si la direction n’est pas à STOP
			Initialise la prochaine position du Snake selon la direction
			Si le Snake ne peut avancer soit à cause des murs ou de lui - même
				Diminue et affiche le nb de vie
				Si nb de vie = 0
					gameOver ← true
				Sinon Si la nouvelle position est celle de la pomme
					Le snake mange une pomme(avance et allonge)
					Augmente et affiche le score
					Génère une nouvelle pomme
				Sinon
					Le Snake avance à cette nouvelle position

				Affiche le Snake
				Attendre 100 millisecondes (Sleep(100);)
		Fin Si
	Fin Tant Que

	Affiche le résultat du jeu
	*/

	Apple a(10,3);
	Snake s;

	s.initialize(10, 5);

	a.draw(cout);
	cout << s;
	system("pause>0");
	s.move(2);
	cout << s;
	system("pause>0");
	

	system("pause");
}