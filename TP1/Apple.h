/****************************************************************************************
* Auteur	: Claudio Cruz et Ramin Amiri					 							*
* Nom		: apple.h																	*
* Date		: 08 avril 2022																*
* Description	: L'objet Aapple impl�ment� avec un tableau primitif dans le jeu snake  	*
****************************************************************************************/

#pragma once

#include "point.h"

class Apple {
private:
	Point _apple;							//position de la pomme
public:
	Apple();								//initialise la positon � 0 et couleur rouge
	Apple(int x, int y);					//initialise la position re�ue
	~Apple();
	void setPosition(int x, int y);			//initialise la pomme � la position re�ue
	const Point& getPoint() const;	 	//retourne la position de la pomme
	void draw(std::ostream& sortie) const;	//draw la pomme rouge
};

std::ostream& operator<<(std::ostream& sortie, const Apple& a);