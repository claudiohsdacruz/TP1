#include <iostream>
#include <cassert>
#include <Windows.h>
#include "point.h"
using namespace std;

Point::Point()
{
	_x = _y = 0;
	_color = 15;
}
Point::Point(int x, int y)
{
	setX(x);
	setY(y);
	_color = 15;
}
Point::~Point()
{
	_color = 0;
	_x = _y = 0;
}
Point::Point(const Point& p)
{
	_x = p._x;
	_y = p._y;
	_color = p._color;
}
void Point::setX(int x)
{
	assert(x >= 0);
	_x = x;
}
void Point::setY(int y)
{
	assert(y >= 0);
	_y = y;
}
void Point::setColor(int color)
{
	assert(color >= 0 && color <= 15);
	_color = color;
}
void Point::setPosition(int x, int y)
{
	setX(x);
	setY(y);
	setColor(15);
}
int Point::getX() const
{
	return _x;
}
int Point::getY() const
{
	return _y;
}
int Point::getColor() const
{
	return _color;
}
void Point::read(istream& input)
{
	char symbole;
	viderBuffer();
	input >> symbole >> _x >> symbole >> _y >> symbole;
}
void Point::print(ostream& output) const
{
	output << "(" << _x << "," << _y << ")";
}
void Point::draw(ostream& output) const
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
const Point& Point::operator=(const Point& p)
{
	_x = p._x;
	_y = p._y;
	_color = p._color;
	return *this;
}
bool Point::operator==(const Point& p) const
{
	if (_x == p._x && _y == p._y)
		return true;
	else
		return false;
}
bool Point::operator!=(const Point& p) const
{
	if (_x != p._x && _y != p._y)
		return true;
	else
		return false;
}
Point Point::operator+(const Point& p)
{
	_x = _y + p._x;
	_y = _y + p._y;
	return *this;
}
Point Point::operator-(const Point& p)
{
	_x = _x - p._x;
	_y = _y - p._y;
	return *this;
}
istream& operator>>(istream& input, Point& p) {
	p.read(input);
	return input;
}
ostream& operator<<(ostream& output, Point& p)
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