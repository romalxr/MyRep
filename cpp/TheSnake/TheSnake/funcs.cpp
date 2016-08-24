#include "stdafx.h"
#include "funcs.h"
#include "direction.h"
#include "globals.h"
#include "figure.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <chrono>
#include <thread>


void setConsolePosition(short x, short y) {
	
	COORD position = { x, y }; //позиция x и y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}

void setConsoleScreenSize() {

	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { BORDER_WIDTH, BORDER_HEIGHT+2 };
	SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);
}

char directionChanged(direction &lastDirect) {
	unsigned char buffer[20];
	int i = 0;
	while (i<20 && _kbhit()) {
		buffer[i] = _getch();
		++i;
	}

	if (i) {
		for (int j = i-1; j > 0; j--) {
			if (buffer[j - 1] == 224) {
				switch (buffer[j]) {
				case 'H': //up
					if (lastDirect != direction::UP && lastDirect != direction::DOWN) {
						lastDirect = direction::UP;
						return true;
					}
					break;
				case 'P': //down
					if (lastDirect != direction::UP && lastDirect != direction::DOWN) {
						lastDirect = direction::DOWN;
						return true;
					}
					break;
				case 'K': //left
					if (lastDirect != direction::LEFT && lastDirect != direction::RIGHT) {
						lastDirect = direction::LEFT;
						return true;
					}
					break;
				case 'M': //right
					if (lastDirect != direction::LEFT && lastDirect != direction::RIGHT) {
						lastDirect = direction::RIGHT;
						return true;
					}
					break;
				default:
					break;
				}
			}
		}
	}

	return false;
}

void pause(int ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void drawScreenBorders() {

	horisontalLine upLine(0, BORDER_WIDTH, 1, BORDER_SYM);
	verticalLine leftLine(1, BORDER_HEIGHT, 0, BORDER_SYM);
	verticalLine rightLine(1, BORDER_HEIGHT, BORDER_WIDTH-1, BORDER_SYM);
	horisontalLine downLine(0, BORDER_WIDTH, BORDER_HEIGHT, BORDER_SYM);

	upLine.draw();
	downLine.draw();
	leftLine.draw();
	rightLine.draw();
}

void printText(int x, int y, std::string s)
{
	setConsolePosition(x, y);
	std::cout << s;
}

void printText(int x, int y, int n)
{
	setConsolePosition(x, y);
	std::cout << n;
}