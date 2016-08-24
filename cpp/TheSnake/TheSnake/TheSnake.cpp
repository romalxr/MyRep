#include "stdafx.h"

#include "point.h"
#include "figure.h"
#include "funcs.h"
#include "globals.h"


int main() {

	short score = 0;
	short pause_len = START_PAUSE;
	direction lastDirect = START_DIRECT;

	setConsoleScreenSize();
	drawScreenBorders();
	
	printText(0, 0, score);

	snake sn(START_X, START_Y, START_LEN, TAIL_SYM, HEAD_SYM, START_DIRECT);
	sn.draw();

	point food(0, 0, FOOD_SYM);
	food.moveRnd();
	while (sn.cross(food)) {
		food.moveRnd();
	}
	food.draw();

	while (true) {
		
		pause(pause_len);

		if (directionChanged(lastDirect)) {
			sn.turn(lastDirect);
		}

		if (sn.dead()) {
			break;
		}
		else if (sn.ate(food)) {
			score += 100;
			printText(0, 0, score);
			pause_len -= 1;
			food.moveRnd();
			while (sn.cross(food)) {
				food.moveRnd();
			}
			food.draw();
		}
		else
			sn.move();		
	}

	sn.clear();
	food.clear();

	pause(3000);
	return 0;
}
