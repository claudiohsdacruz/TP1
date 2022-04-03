#pragma once

class Point
{
private:
	int _x, _y;
	int _color;
public:
	//Constructeur
	Point();
	Point(int x, int y);
	//Destructeur
	~Point();
	//Constructeur de copie
	Point(const Point& p);
	//Setteur
	void setX(int x);
	void setY(int y);
	void setColor(int color);
	void setPosition(int x, int y);
	//Getteur
	int getX() const;
	int getY() const;
	int getColor() const;
	//Autres m�thodes
	void read(std::istream& input);
	void print(std::ostream& output) const;
	void draw(std::ostream& output) const;
	//Op�rateur de surchage
	const Point& operator=(const Point& p);
	bool operator==(const Point& p) const;
	bool operator!=(const Point& p) const;
	Point operator+(const Point& p);
	Point operator-(const Point& p);
};
void viderBuffer();
void gotoxy(int xpos, int ypos);
std::istream& operator>>(std::istream& input, Point& p);
std::ostream& operator<<(std::ostream& output, Point& p);