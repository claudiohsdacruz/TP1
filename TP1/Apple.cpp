/************************************************************************************
* Auteur	: Claudio Cruz et Ramin	Amiri											*
* Nom		: apple.cpp																*
* Date		: 08 avril 2022															*
* Description : Implementation des constucteurs et méthodes de la classe Apple		*
************************************************************************************/

#include <iostream>
#include <cassert>
#include <Windows.h>

#include "apple.h"
#include "point.h"

// Constructeur sans parâmetres
Apple::Apple()
{
	_apple = Point();
	_apple.setColor(4);
}

// Constructeur avec les parâmetres de position
Apple::Apple(int x, int y)
{
	_apple = Point(x, y);
	_apple.setColor(4);
}

// Destructeur
Apple::~Apple()
{
	_apple = Point();
	_apple.setColor(0);
}

// Ajuoute une nouvelle position à la Pomme
void Apple::setPosition(int x, int y)
{
	_apple.setX(x);
	_apple.setY(y);
}

// Retourne l'objet pomme
const Point& Apple::getPoint() const
{
	return _apple;
}

// Affiche la pomme
void Apple::draw(std::ostream& sortie) const
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _apple.getColor());
	gotoxy(_apple.getX(), _apple.getY());
	_apple.draw(sortie);
}

// Define l'operateur de sortie '<<'
std::ostream& operator<<(std::ostream& sortie, const Apple& a)
{
	a.draw(sortie);
	return sortie;
}
