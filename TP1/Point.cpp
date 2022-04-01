#include <iostream>
#include <cassert>
#include <Windows.h>
#include "point.h"
using namespace std;

point::point()
{
	_x = _y = 0;
	_color = 15;
}
point::point(int x, int y)
{
	setX(x);
	setY(y);
	_color = 15;
}
point::~point()
{
	_color = 0;
	_x = _y = 0;
}
point::point(const point& p)
{
	_x = p._x;
	_y = p._y;
	_color = p._color;
}
void point::setX(int x)
{
	assert(x >= 0);
	_x = x;
}
void point::setY(int y)
{
	assert(y >= 0);
	_y = y;
}
void point::setColor(int color)
{
	assert(color >= 1 && color <= 15);
	_color = color;
}
void point::setPosition(int x, int y)
{
	setX(x);
	setY(y);
	setColor(15);
}
int point::getX() const
{
	return _x;
}
int point::getY() const
{
	return _y;
}
int point::getColor() const
{
	return _color;
}
void point::read(istream& input)
{
	char symbole;
	viderBuffer();
	input >> symbole >> _x >> symbole >> _y >> symbole;
}
void point::print(ostream& output) const
{
	output << "(" << _x << "," << _y << ")";
}
void point::draw(ostream& output) const
{
	output << "\xFE";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
	gotoxy(_x, _y);
}
//fonction pour se positionner dans l'écran à x,y
void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos;
	scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
const point& point::operator=(const point& p)
{
	_x = p._x;
	_y = p._y;
	_color = p._color;
	return *this;
}
bool point::operator==(const point& p) const
{
	if (_x == p._x && _y == p._y)
		return true;
	else
		return false;
}
bool point::operator!=(const point& p) const
{
	if (_x != p._x && _y != p._y)
		return true;
	else
		return false;
}
point point::operator+(const point& p)
{
	_x = _y + p._x;
	_y = _y + p._y;
	return *this;
}
point point::operator-(const point& p)
{
	_x = _x - p._x;
	_y = _y - p._y;
	return *this;
}
istream& operator>>(istream& input, point& p) {
	p.read(input);
	return input;
}
ostream& operator<<(ostream& output, point& p)
{
	p.print(output);
	return output;
}
void viderBuffer() {
	cin.clear();
	cin.seekg(0, ios::end);
	if (!cin.fail())
		cin.ignore();
	else
		cin.clear();
}