/****************************************************************************************
* Auteur	: Claudio Cruz et Ramin Amiri					 							*
* Nom		: rectangle.h																*
* Date		: 08 avril 2022																*
* Description	: L'objet Rectangle utilisé pour la construction du tableau de jeu  	*
****************************************************************************************/

#pragma once

#include "point.h"

class Retangle
{
private:
	Point _coord;
	int _w;
	int _h;
public:
	//Constructeurs
	Retangle();
	Retangle(int x, int y, int w = 0, int h = 0);
	//Destructeur
	~Retangle();
	//Getteur
	int getLargeur() const;
	int getHauteur() const;
	Retangle getRectangle() const;
	Point& getPosition();
	//Setteur
	void setLargeur(int w);
	void setHauteur(int h);
	void setCoord(int x, int y);
	void setRectangle(int w, int h);
	void setRectangle(int x, int y, int w = 0, int h = 0);
	//Autres méthodes
	void read(std::istream& input);
	void print(std::ostream& output) const;
	void draw(std::ostream& output) const;
};