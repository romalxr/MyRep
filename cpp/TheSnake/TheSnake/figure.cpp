#include "stdafx.h"

#include <list>
#include "figure.h"
#include "point.h"
#include "globals.h"
#include "direction.h"
#include <string>

void figure::draw() {
	for (std::list<point>::iterator it = line.begin(); it != line.end(); it++)
		(*it).draw();
}

void figure::clear() {
	for (std::list<point>::iterator it = line.begin(); it != line.end(); it++)
		(*it).clear();
}

horisontalLine::horisontalLine(int xLeft, int xRight, int y, char sym) {
	for (int x = xLeft; x < xRight; x++) {
		point tmp(x, y, sym);
		line.push_back(tmp);
	}
}

verticalLine::verticalLine(int yUp, int yDown, int x, char sym) {
	for (int y = yUp; y < yDown; y++) {
		point tmp(x, y, sym);
		line.push_back(tmp);
	}
}

snake::snake(int x, int y, int len, char sym, char headSym, direction direct) {
	
	this->len = len;
	this->direct = direct;
	for (int i = 0; i < len-1; i++) {		
		point tmp(x, y, sym);
		tmp.move(this->direct, i);
		line.push_back(tmp);
	}

	point tmp(x, y, headSym);
	tmp.move(this->direct, len - 1);
	line.push_back(tmp);
}

void snake::move() {

	point tail = line.front();
	point head = line.back();
	tail.clear();
	tail.setcoord(head);
	tail.draw();

	head.move(direct, 1);
	head.draw();

	line.pop_front();
	line.pop_back();
	line.push_back(tail);
	line.push_back(head);
}

void snake::turn(direction direct) {
	
	this->direct = direct;
}

char snake::ate(const point &p) {
	point tail = line.front();
	point head = line.back();
	tail.setcoord(head);
	head.move(direct, 1);
	if (head.cross(p)) {
		head.draw();
		tail.draw();
		line.pop_back();
		line.push_back(tail);
		line.push_back(head);

		++len;
		return true;
	}
	return false;
}

char figure::cross(const point &p) {
	for (std::list<point>::iterator it = line.begin(); it != line.end(); it++){
		if ((*it).cross(p))
			return true;
	}
	return false;
}

char snake::dead() {
	point head = line.back();
	point tail = line.front();
	head.move(direct, 1);
	if (head.crossBorders())
		return true;
	if (!head.cross(tail) && cross(head))
		return true;
	return false;
}