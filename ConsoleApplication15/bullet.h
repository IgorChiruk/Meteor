#pragma once
class bullet
{ 
protected:
	int cord=0;
	bool state=false;
public:
	void setState(int i);
	bool getState();
	void destroy();
	virtual void upCord();
	int getCord();
	bullet();
	~bullet();
};

