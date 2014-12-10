#include "InputHandler.h"

#ifndef BACKGROUND_H
#define BACKGROUND_H

class Background
{
public:
    Background()
    {
	_x1 = 0;
	_x2 = 0;
    }

    ~Background() = default;

    int getX1();
    void setX1(int x1);

    int getX2();
    void setX2(int x2);

private:
    int _x1;
    int _x2;
};

#endif

