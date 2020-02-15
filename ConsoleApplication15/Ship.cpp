#include "stdafx.h"
#include "Ship.h"



void Ship::upCord()
{
	if (cord < 31) { cord++; }
}

void Ship::downCord()
{
	if (cord > 0) { cord--; }
}

int Ship::getCord()
{
	return cord;
}

void Ship::destroy()
{
	state = false;
}

bool Ship::getState()
{
	return state;
}

int Ship::getmas(int i, int j)
{
	return mas[i][j];
}

Ship::Ship()
{
	cord = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			mas[i][j] = 0;
		}
	}
	mas[0][1] = 2;
	mas[0][5] = 2;
	mas[0][3] = 1;
	for (int j = 0; j < 7; j++) {
		mas[1][j] = 1;
	}
	for (int j = 2; j < 5; j++) {
		mas[2][j] = 1;
	}
	mas[3][3] = 1;
}
// | H |
//HHHHHHH
//  HHH
//   H

Ship::~Ship()
{
}
