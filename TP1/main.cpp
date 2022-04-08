/************************************************************************************
* Auteur	: Claudio Cruz et Ramin	Amiri											*
* Nom		: main.cpp																*
* Date		: 03 avril 2022															*
* Description : Le Snake est un jeu où un serpent a pour bout manger tous les		*
*		  pommes afficher sur le tableau. Les fléches servent à déplacer le snake	*
*		  sur le tableau, mais attention de ne pas toucher les côté ou le snake		*
*		  lui-même. 																*
************************************************************************************/
#include <iostream>
#include <cassert>
#include <Windows.h>
#include "point.h"
#include "snake.h"
#include "apple.h"
#include "game.h"
#include "rectangle.h"

using namespace std;

void main() {
	
	
	Game game; //Crée le jeu
	
	game.play(); //Commence le jeu


	
/*
	Apple a(10,3);
	Snake s;

	cout << a.getPoint().getX();

	

	s.initialize(10, 5);

	a.draw(cout);
	cout << s;
	system("pause>0");
	s.move(3);
	cout << s;
	system("pause>0");
	s.move(3);
	cout << s;
	s.eat(3);
	system("pause>0");
	s.move(3);
	cout << s;
	system("pause>0");
	s.move(3);
	cout << s;
	system("pause>0");
	s.move(2);
	cout << s;
	system("pause>0");
	s.move(2);
	cout << s;
	system("pause>0");
	s.move(2);
	cout << s;
	system("pause>0");
	s.move(2);
	cout << s;
	system("pause>0");
	s.move(2);
	cout << s;
*/
	system("pause>0");
}