#include "stdafx.h"
#include "Meteor.h"


void Meteor::upCord()
{
	if (cord < 27) { cord++; }
	if (cord == 27) { state = false; cord = 0; }
}

Meteor::Meteor()
{
	for (int i=0;i<2;i++) {
		for (int j = 0; j < 2; j++) {
			mas[i][j] = 4;
		}
	}
}


Meteor::~Meteor()
{
}
