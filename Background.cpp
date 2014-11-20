#include "Background.h"


Background::Background()
{
	_x = 0;
}


Background::~Background()
{

}

void Background::setX(int x)
{
	_x = x;
}

int Background::getX()
{
	return _x;
}