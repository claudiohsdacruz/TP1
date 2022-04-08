/****************************************************************************************
* Auteur	: Claudio Cruz et Ramin Amiri					 							*
* Nom		: apple.h																	*
* Date		: 08 avril 2022																*
* Description	: L'objet Aapple implémenté avec un tableau primitif dans le jeu snake  	*
****************************************************************************************/

#pragma once

#include "point.h"

class Apple {
private:
	Point _apple;							//position de la pomme
public:
	Apple();								//initialise la positon à 0 et couleur rouge
	Apple(int x, int y);					//initialise la position reçue
	~Apple();
	void setPosition(int x, int y);			//initialise la pomme à la position reçue
	const Point& getPoint() const;	 	//retourne la position de la pomme
	void draw(std::ostream& sortie) const;	//draw la pomme rouge
};

std::ostream& operator<<(std::ostream& sortie, const Apple& a);