#include "direction.h"
#include "globals.h"

#ifndef __POINT_H__
#define __POINT_H__

class point{
public:
	point();
	point(int x, int y, char sym);
	point(const point &p);
	void draw();
	void move(direction direct, int range);
	void moveRnd();
	void clear();
	void setcoord(const point &p);
	char cross(const point &p);
	char crossBorders();

protected:
	int x;
	int y;
	char sym;
};

#endif // __POINT_H__
