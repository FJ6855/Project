#include "Background.h"


Background::Background()
{
	_x1 = 0;
	_x2 = 0;
}


Background::~Background()
{

}

void Background::setX1(int x1)
{
	_x1 = x1;
}

int Background::getX1()
{
	return _x1;
}

void Background::setX2(int x2)
{
	_x2 = x2;
}

int Background::getX2()
{
	return _x2;
}
