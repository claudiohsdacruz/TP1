#include <iostream>
#include <cassert>
#include <Windows.h>

#include "game.h"

/*
void Game::inputKey() {
	int touche;
	if (_kbhit()) {			//si une touche est enfonc�e
		touche = _getch();		//saisit la touche

		if (touche == 'q') {		//si la touche est q, on veut arr�ter le jeu
			_gameOver = true;
			_dir = STOP;
		}
		else if (touche == 224) {	//si la touche est 224, c�est une fl�che
			touche = _getch();	//dans le buffer on prend la 2e partie de la touche
			switch (touche) {
			case 75:		//code ascii des fl�ches
				_dir = LEFT;
				break;
			case 72:
				_dir = UP;
				break;
			case 80:
				_dir = DOWN;
				break;
			case 77:
				_dir = RIGHT;
			}
		}
	}
}
*/
