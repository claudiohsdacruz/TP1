/************************************************************************************
* Auteur	: Claudio Cruz et Ramin	Amiri											*
* Nom		: snake.cpp																*
* Date		: 08 avril 2022															*
* Description : Implementation des constucteurs et méthodes de la classe Snake		*
************************************************************************************/

#include <iostream>
#include <cassert>
#include <Windows.h>

#include "snake.h"
#include "apple.h"

using namespace std;

Snake::Snake()
{
	_snake[0] = Point(20, 10);
	_size = 6;
}

Snake::Snake(int x, int y)
{
	_snake[0] = Point(x, y);
	_size = 6;
}

Snake::~Snake()
{
	_snake[0] = Point(0, 0);
	_size = 0;
}

void Snake::initialize(int x, int y)
{
	for (int i = 0; i < _size; i++)
	{
		_snake[i] = Point(x - i, y);
	}
}

const Point& Snake::getHeadPosition() const
{
	return _snake[0];
}

const Point& Snake::getPosition(int ind) const
{
	return _snake[ind];
}

const Point& Snake::operator[](int ind) const
{
	Point p;
	p.setX(_snake[ind].getX());
	p.setY(_snake[ind].getY());
	p.setColor(_snake[ind].getColor());
	return p;
}

int Snake::getSize() const
{
	return _size;
}

Point Snake::newPosition(int dir) const
{
	Point newPoint;
	switch (dir)
	{
	case 1:
		newPoint.setX(_snake[0].getX() - 1);
		newPoint.setY(_snake[0].getY());
		break;
	case 2:
		newPoint.setX(_snake[0].getX() + 1);
		newPoint.setY(_snake[0].getY());
		break;
	case 3:
		newPoint.setX(_snake[0].getX());
		newPoint.setY(_snake[0].getY() - 1);
		break;
	case 4:
		newPoint.setX(_snake[0].getX());
		newPoint.setY(_snake[0].getY() + 1);
		break;
	default:
		break;
	}
	return newPoint;
}

bool Snake::ifCollision(const Point& pos) const
{
	bool collision = false;
	for (int i = 1; i < _size; i++)
	{
		if (pos.getX() == _snake[i].getX() && pos.getY() == _snake[i].getY())
		{
			collision = true;
		}
	}
	return collision;
}

void Snake::move(int dir)
{
	_snake[_size].setColor(0);
	_snake[_size].draw(cout);
	Point newHead = newPosition(dir);	
	for (int i = _size -1; i >= 0 ; i--)
	{	
		_snake[i] = _snake[i - 1]; 
	}
	_snake[_size -1].setColor(0);
	_snake[0] = newHead;
	
}

void Snake::eat(int dir)
{
	move(dir);
	if (_size <=25)
	{
		_size++;
	}

}

void Snake::draw(std::ostream& sortie) const
{
	for (int i = 0; i < _size; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _snake[i].getColor());
		gotoxy(_snake[i].getX(), _snake[i].getY());
		_snake[i].draw(sortie);
	}
}

void Snake::deleteSnake()
{
	for (int i = 0; i < _size; i++)
	{
		_snake[i].setColor(0);
		_snake[i].draw(cout);
	}
}

std::ostream& operator<<(std::ostream& sortie, const Snake& s)
{
	s.draw(sortie);
	return sortie;
}