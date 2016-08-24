#include "direction.h"
#include "globals.h"
#include <string>

#ifndef __FUNCS_H__
#define __FUNCS_H__

void setConsolePosition(short x, short y);
void setConsoleScreenSize();
void pause(int ms);
char directionChanged(direction &lastDirect);
void drawScreenBorders();
void printText(int x, int y, std::string s);
void printText(int x, int y, int n);

#endif // __FUNCS_H__