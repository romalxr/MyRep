#include <list>
#include "point.h"
#include "globals.h"
#include <string>

#ifndef __FIGURE_H__
#define __FIGURE_H__

class figure
{
public:
	void draw();
	void clear();
	char cross(const point &p);

protected:
	std::list <point> line;
};

class horisontalLine : public figure {

public:
	horisontalLine(int xLeft, int xRight, int y, char sym);
};

class verticalLine : public figure {

public:
	verticalLine(int yUp, int yDown, int x, char sym);
};

class snake : public figure {

public:
	snake(int x, int y, int len, char sym, char headSym, direction direct);
	void move();
	void turn(direction direct);
	char ate(const point &p);	
	char dead();

private:
	short len;
	direction direct;
};

#endif // __FIGURE_H__