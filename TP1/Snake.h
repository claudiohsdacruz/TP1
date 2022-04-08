/****************************************************************************************
* Auteur	: Claudio Cruz et Ramin Amiri					 							*
* Nom		: snake.h																	*
* Date		: 03 avril 2022																*
* Description	: L'objet snake implémenté avec un tableau primitif de point et une		*
*               taille pouvant se déplacer pour être intégré dans le jeu snake    		*
****************************************************************************************/
#pragma once
# include "point.h"

class Snake {
private:
	Point _snake[800];					//tableau pour toutes les positions du snake
	int _size;							//taille réelle du snake
public:
	Snake();							//initialise le snake à l’origine, à partir d’une  
	Snake(int x, int y);				//position ou d’une coordonnée (x, y) et de taille 6
	~Snake();							//remet le _size à 0

	void initialize(int x, int y);		//initialise le snake à partir de (x, y) de taille 6

	const Point& getHeadPosition() const;		//retourne la position de la tête du snake
	const Point& getPosition(int ind) const;	//retourne la position à l’indice reçue
	const Point& operator[](int ind) const;		//opérateur qui appelle getteur de position
	int getSize()const;							//retourne la taille du snake

	Point newPosition(const int dir) const;	        //retourne la nouvelle position selon la direction

	bool ifCollision(const Point& pos) const;	//retourne vrai si la position reçue est en
												//collision avec une des positions du snake
	void move(const int dir);							//avance le snake dans la bonne direction
	void eat(const int dir);							//avance et mange une pomme dans la direction

	void draw(std::ostream& sortie) const;		//draw le snake

	void deleteSnake(); //Efface le serpent
};

std::ostream& operator<<(std::ostream& sortie, const Snake& s);