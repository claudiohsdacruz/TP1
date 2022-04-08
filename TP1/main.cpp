/************************************************************************************
* Auteur	: Claudio Cruz et Ramin	Amiri											*
* Nom		: main.cpp																*
* Date		: 08 avril 2022															*
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


	system("pause>0");
}