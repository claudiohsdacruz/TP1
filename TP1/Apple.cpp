#include <iostream>
#include <cassert>
#include <Windows.h>

#include "apple.h"
#include "point.h"

Apple::Apple()
{
	_apple = Point();
	_apple.setColor(4);
}

Apple::Apple(int x, int y)
{
	_apple.setPosition(x, y);
	_apple.setColor(4);
}

void Apple::setPosition(int x, int y)
{
	_apple.setX(x);
	_apple.setY(y);
}

const Point& Apple::getPosition() const
{
	Point p;
	p.setPosition(_apple.getX(), _apple.getY());
	return p;
}

void Apple::draw(std::ostream& sortie) const
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _apple.getColor());
	gotoxy(_apple.getX(), _apple.getY());
	_apple.draw(sortie);

}

std::ostream& operator<<(std::ostream& sortie, const Apple& a)
{
	a.draw(sortie);
	return sortie;
}
