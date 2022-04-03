#include <iostream>
#include <cassert>
#include <Windows.h>

#include "snake.h"
#include "apple.h"


Snake::Snake()
{
	_snake[0] = Point(0, 0);
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
	_snake[0] = Point(x, y);
	_size = 6;
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
	return Point();
}

bool Snake::ifCollision(const Point& pos) const
{
	return false;
}

void Snake::move(int dir)
{
	for (int i = 0; i < _size; i++)
	{

	}
}

void Snake::eat(int dir)
{
	Apple apple;
	if (_snake[0].getX() == apple.getPosition().getX() && _snake[0].getY() == apple.getPosition().getY())
	{
		if (_size <= 15)
		{
			_size += 1;
		}
	}
}

void Snake::draw(std::ostream& sortie) const
{
	for (int i = 0; i < _size; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _snake[0].getColor());
		gotoxy(_snake[i].getX(), _snake[i].getY());
		_snake[i].draw(sortie);
	}
}

std::ostream& operator<<(std::ostream& sortie, const Snake& s)
{
	s.draw(sortie);
	return sortie;
}
