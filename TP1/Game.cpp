/************************************************************************************
* Auteur	: Claudio Cruz et Ramin	Amiri											*
* Nom		: game.cpp																*
* Date		: 08 avril 2022															*
* Description : Implementation des constucteurs et méthodes de la classe Game		*
************************************************************************************/

#include <iostream>
#include <cassert>
#include <Windows.h>
#include <conio.h>

#include "game.h"
#include "point.h"
#include "rectangle.h"
#include "snake.h"
#include "apple.h"

using namespace std;

// Constructeur sans parâmetres
Game::Game()
{
	_lose = false;
	_dir = 0;
	_cptLive = 0;
	_score= 0;
	_speed = 2;
	_snake = Snake();
	_apple = Apple();
	_plateau = Retangle();
}

// Destructeur
Game::~Game()
{
	_lose = false;
	_dir = 0;
	_cptLive = 3;
	_score = 0;
	_apple.~Apple();
	_snake.~Snake();
	_plateau.~Retangle();
}

// Intialise le jeu ave les paramètres de base
void Game::initialize()
{
	_lose = false;
	_dir = 0;
	_cptLive = 3;
	_snake = Snake();
	_apple = Apple(randPosition().getX(), randPosition().getY());
	_plateau = Retangle(0, 0, _width, _height);

	_plateau.draw(cout);
	_apple.draw(cout);
	_snake.initialize(_snake.getHeadPosition().getX(), _snake.getHeadPosition().getY());
	_snake.draw(cout);
	this->printScore(cout);
	this->printLive(cout);
}

// Génére une position aleatoire sur le tableau du jeu
Point Game::randPosition() const
{
	int x, y;
	x = (rand() % 38) + 1;
	y = (rand() % 18) + 1;
	return Point(x,y);
}

// Génére et affiche une pomme sur le tableau
void Game::createApple()
{
	Point a = randPosition();
	do
	{
		Point a = randPosition();
		_apple.setPosition(a.getX(), a.getY());
	} while (_snake.ifCollision(a)); // verifie se la position de la pomme est genere sur un serpent
	_apple.draw(std::cout);
}

// Faire functioner la mécanique du jeu
void Game::play()
{
	srand(time(NULL)); 
	this->initialize(); //Initialise la Game(initialise le booléen, les vies, le score, le Snake et la première pomme)

	while (!_lose)
	{
		
		Point p = _snake.getHeadPosition(); //Prend la position de la tete du serpent
		Point a = _apple.getPoint(); //Prend la position de la pomme
		Point newPosition;
		
		this->printScore(cout); //Affiche le score
		do
		{	
			this->inputKey(); //Saisit la touche
			newPosition = _snake.newPosition(_dir);
		} while (!this->canMove(newPosition));
		
		if (_dir != 0)
		{
			cout << _snake; //Initialise la prochaine position du Snake selon la direction
	
			if (_snake.ifCollision(p) || _snake.getHeadPosition().getX() == 39 || _snake.getHeadPosition().getX() == 0 || 
				_snake.getHeadPosition().getY() == 19 || _snake.getHeadPosition().getY() == 0) 
			{
				_snake.deleteSnake();	//Efface le serpent
				_cptLive--;				//Diminue le nb de vie
				_snake.initialize(20, 10); //Inicialize une nouvelle serpent
				_plateau.draw(cout);	//Affiche le plateau du jeu
				_dir = 2;				//Initialise une direction
				this->printLive(cout); //Affiche le nb de vie
				if (_cptLive == 0)
				{
					this->endGame();	//finalise le jeu
				}
			}
			else if (p.getX() == a.getX() && p.getY() == a.getY())
			{
				_snake.eat(_dir); //Le snake mange une pomme(avance et allonge)
				_score++; //Augmente le score
				this->printScore(cout); //Affiche le score
				this->createApple(); //Génère une nouvelle pomme
			}
			else
			{
				_snake.move(_dir); //Le Snake avance à cette nouvelle position
			}
			//Vitesse du serpente
			if (_score < 10 )
			{
				Sleep(100 * _speed);
			}
			else
			{
				Sleep(50 * _speed); //Augment la vitesse si le score est plus grande que 10
			}

			
		}
	}

	this->printEndGame(cout); //Affiche la message de fin du jeu
}

// Saisit les touches et change la direction et le bool _gameOver si on touche q
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

// Verifie si le serpent peut bouger
bool Game::canMove(const Point& p) const
{
	bool move = true;
	int px = p.getX();
	int sx = _snake.getPosition(1).getX();
	int py = p.getY();
	int sy = _snake.getPosition(1).getY();
	if (px == sx && py == sy)
	{
		move = false;
	}
	return move;
}

// Retourne le score
int Game::getScore() const
{
	return _score;
}

// Finalise le jeu
void Game::endGame()
{
	_lose = true;
}

// Affiche le score
void Game::printScore(std::ostream& sortie) const
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(0, 21);
	sortie << "Score : " << _score;
}

// Affiche la quantité de vie
void Game::printLive(std::ostream& sortie) const
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(0, 22);
	sortie << "Live : " << _cptLive;
}

// Affiche la fin du jeu
void Game::printEndGame(std::ostream& sortie) const
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(0, 23);
	sortie << "GAME OVER!";
}

// affiche une serpent
void Game::printSnake(std::ostream& sortie) const
{
	sortie << _snake;
}


