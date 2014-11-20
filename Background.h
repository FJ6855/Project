#include "InputHandler.h"

#ifndef BACKGROUND_H
#define BACKGROUND_H

class Background
{
public:
	Background();
	~Background();

	void setX(int x);
	int getX();

private:
	int _x;
};


#endif

