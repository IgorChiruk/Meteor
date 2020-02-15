#include "stdafx.h"
#include "bullet.h"


void bullet::setState(int i)
{
	if (i == 1) { state = true; }
	if (i == 0) { state = false; }
}

bool bullet::getState()
{
	return state;
}

void bullet::destroy()
{
	state = false;
	cord = 0;
}

void bullet::upCord()
{
	if (cord < 23) { cord++; }
	if (cord == 23) { state = false; cord = 0; }
}

int bullet::getCord()
{
	return cord;
}

bullet::bullet()
{
}


bullet::~bullet()
{
}
