#include <iostream>
#include <assert.h>
#include <Windows.h>
#include "point.h"
#include "rectangle.h"

using namespace std;

Retangle::Retangle()
{
	_w = _h = 0;
}
Retangle::Retangle(int x, int y, int w, int h)
{
	setRectangle(x, y, w, h);
}
Retangle::~Retangle()
{
	_w = _h = 0;
}
int Retangle::getHauteur() const
{
	return _h;
}
Retangle Retangle::getRectangle() const
{
	return Retangle();
}
int Retangle::getLargeur() const
{
	return _w;
}

Point& Retangle::getPosition()
{
	return _coord;
}
void Retangle::setLargeur(int w)
{
	assert(w >= 0);
	_w = w;
}
void Retangle::setHauteur(int h)
{
	assert(h >= 0);
	_h = h;
}
void Retangle::setCoord(int x, int y)
{
	_coord.setX(x);
	_coord.setY(y);
}
void Retangle::setRectangle(int w, int h)
{
	setLargeur(w);
	setHauteur(h);
}
void Retangle::setRectangle(int x, int y, int w, int h)
{
	setCoord(x, y);
	setLargeur(w);
	setHauteur(h);
}
//Saisi selon le format (x,y) w X h
void Retangle::read(istream& input)
{
	char lettre;
	int x, y;
	viderBuffer();
	input >> lettre >> x >> lettre >> y >> lettre >> lettre >> _w >> lettre >>
		_h;
	_coord.setPosition(x, y);
}
void Retangle::print(ostream& output) const
{
	_coord.print(output);
	output << " " << _w << " X " << _h;
}
void Retangle::draw(ostream& output) const
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _coord.getColor
	());
	gotoxy(_coord.getX(), _coord.getY());
	for (int i = 0; i < _w; i++)
		output << "*";
	for (int i = 0; i < _h - 2; i++) {
		gotoxy(_coord.getX(), _coord.getY() + i + 1);
		output << "*";
		gotoxy(_coord.getX() + _w - 1, _coord.getY() + i + 1);
		output << "*";
	}
	gotoxy(_coord.getX(), _coord.getY() + _h - 1);
	for (int i = 0; i < _w; i++)
		output << "*";
}
