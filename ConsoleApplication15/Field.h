#pragma once
#include "Ship.h"
#include "bullet.h"
#include "Meteor.h"

public class Field
{
	int mas[28][39];
	int cordF;
	int cordM;
	Ship s;
	bullet b;
	Meteor m;
public:
	void move(int i);
	void fire();
	bool met();
	bool getState();
	void zapusk(int i);
	void UpdateField();
	Field();
};

