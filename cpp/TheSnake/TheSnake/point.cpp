#include "stdafx.h"
#include "point.h"
#include "globals.h"
#include "direction.h"
#include "funcs.h"
#include <time.h>
#include <iostream>

point::point() {
	this->x = 1;
	this->y = 1;
	this->sym = ' ';
}
point::point(int x, int y, char sym) {
	this->x = x;
	this->y = y;
	this->sym = sym;
}

point::point(const point &p) {
	this->x = p.x;
	this->y = p.y;
	this->sym = p.sym;
}


void point::draw() {
	setConsolePosition(x, y);
	std::cout << sym;
}

void point::move(direction direct, int range) {

	switch (direct) {
	case RIGHT:
		x += range;
		break;
	case LEFT:
		x -= range;
		break;
	case UP:
		y -= range;
		break;
	case DOWN:
		y += range;
		break;
	default:
		break;
	}
}

void point::moveRnd() {

	srand((unsigned int)time(0));
	x = rand() % (BORDER_WIDTH - 3) + 1;
	y = rand() % (BORDER_HEIGHT - 3) + 2;
}

void point::clear() {

	setConsolePosition(x, y);
	std::cout << ' ';
}

void point::setcoord(const point &p) {

	this->x = p.x;
	this->y = p.y;
}

char point::cross(const point &p) {
	
	if (this->x == p.x && this->y == p.y)
		return true;
	return false;
}

char point::crossBorders() {

	if (x < 1 || x > BORDER_WIDTH - 2)
		return true;
	else if (y < 2 || y > BORDER_HEIGHT - 1)
		return true;
	else
		return false;
}