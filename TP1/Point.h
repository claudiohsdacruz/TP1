#pragma once

class point
{
private:
	int _x, _y;
	int _color;
public:
	//Constructeur
	point();
	point(int x, int y);
	//Destructeur
	~point();
	//Constructeur de copie
	point(const point& p);
	//Setteur
	void setX(int x);
	void setY(int y);
	void setColor(int color);
	void setPosition(int x, int y);
	//Getteur
	int getX() const;
	int getY() const;
	int getColor() const;
	//Autres méthodes
	void read(std::istream& input);
	void print(std::ostream& output) const;
	void draw(std::ostream& output) const;
	//Opérateur de surchage
	const point& operator=(const point& p);
	bool operator==(const point& p) const;
	bool operator!=(const point& p) const;
	point operator+(const point& p);
	point operator-(const point& p);
};
void viderBuffer();
void gotoxy(int xpos, int ypos);
std::istream& operator>>(std::istream& input, point& p);
std::ostream& operator<<(std::ostream& output, point& p);