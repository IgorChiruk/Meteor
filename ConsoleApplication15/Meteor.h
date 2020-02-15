#pragma once
#include "bullet.h"
class Meteor :
	public bullet
{
	int mas[2][2];
public:
	void upCord();
	Meteor();
	~Meteor();
};

