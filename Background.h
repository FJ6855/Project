#include "InputHandler.h"

#ifndef BACKGROUND_H
#define BACKGROUND_H

class Background
{
public:
	Background();
	~Background();

	void setX1(int x1);
	int getX1();
	void setX2(int x2);
	int getX2();


private:
	int _x1;
	int _x2;
};


#endif

