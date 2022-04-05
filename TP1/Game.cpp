#include <iostream>
#include <cassert>
#include <Windows.h>
#include <conio.h>

#include "game.h"
#include "point.h"
#include "rectangle.h"


Game::Game()
{
	_lose = false;
	_dir = 0;
	_cptLive = 3;
	_score= 0;
	_plateau = Retangle(0, 0, _width, _height);

}

Game::~Game()
{
	_lose = false;
	_dir = 0;
	_cptLive = 0;
	_score = 0;
	_plateau = Retangle(0, 0, 0, 0);
}

void Game::initialize()
{
	_lose = false;
	_dir = 0;
	_cptLive = 3;
	_score = 0;
	_plateau = Retangle(0, 0, _width, _height);
}

Point Game::randPosition() const
{
	int x, y;
	x = (rand() % 40) + 1;
	y = (rand() % 20) + 1;
	return Point(x,y);
}

void Game::createApple()
{
	Point a = randPosition();
	_apple.setPosition(a.getX(), a.getY());
}

void Game::play()
{

}

void Game::inputKey() {
	int touche;
	if (_kbhit()) {			//si une touche est enfoncée
		touche = _getch();		//saisit la touche

		if (touche == 'q') {		//si la touche est q, on veut arrêter le jeu
			_lose = true;
			_dir = STOP;
		}
		else if (touche == 224) {	//si la touche est 224, c’est une flèche
			touche = _getch();	//dans le buffer on prend la 2e partie de la touche
			switch (touche) {
			case 75:		//code ascii des flèches
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

bool Game::canMove(const Point& p) const
{
	return false;
}

int Game::getScore() const
{
	return 0;
}

void Game::printScore(std::ostream& sortie) const
{
}

void Game::printLive(std::ostream& sortie) const
{
}

void Game::printEndGame(std::ostream& sortie) const
{
}

