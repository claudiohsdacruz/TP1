/************************************************************************************
* Auteur	: Claudio Cruz et Ramin	Amiri											*
* Nom		: game.h																*
* Date		: 03 avril 2022															*
* Description : La classe Game implémente Le jeu Snake en console où les flèches 	*
*		  servent  à déplacer le snake dans l’écran pour manger les pommes,			*
*		  mais attention de ne pas toucher les côté ou le snake lui-même. 			*
************************************************************************************/

#pragma once

#include "snake.h"
#include "apple.h"
#include "point.h"
#include "rectangle.h"

/*
class Game {
private:
	bool _lose;				//si on perd

	int _dir,				//la direction choisie
		_cptLive,			//le compteur de vie
		_score;				//le score de la game

	Snake _snake;				//le snake
	Apple _apple;				//la pomme

	Retangle _plateau;			//rectangle du terrain de jeu
	const int _width = 40;		//dimension du terrain de jeu
	const int _height = 20;

	enum direction { STOP, LEFT, RIGHT, UP, DOWN, NONE };
public:

	Game();				//initialise les types primitifs à 0
	~Game();				//initialise les types primitifs à 0
	void initialize();			//initalise le jeu

	Point randPosition()const;		//génère une nouvelle position aléatoire dans le terrain
	void createApple();			//génère une nouvelle pomme TQ position est dans le snake

	void play();				//la main loop du jeu
	void inputKey();			//la saisie des touches pour le déplacement du snake
	bool canMove(const Point& p) const;//retourne vrai si la tête du snake peut bouger

	int getScore() const;		//retourne le score (seule info qui pourrait être intéressante
	//de l’extérieur) et aucun setteur pour cet objet.

	void printScore(std::ostream& sortie) const;	//affiche le score
	void printLive(std::ostream& sortie) const;	//affiche le compteur de vie
	void printEndGame(std::ostream& sortie) const;//affiche game over et le score

};
*/