#pragma once
public class Ship
{
	int cord;
	int mas[4][7];
	bool state = true;
public:
	void upCord();
	void downCord();
	void destroy();
	bool getState();
	int getCord();
	int getmas(int i, int j);

	Ship();
	~Ship();
};
// | H |
//HHHHHHH
//  HHH
//   H