#include "Score.h"

int Score::getPos()
{
    return _pos;
}

void Score::setPos(int pos)
{
    _pos = pos;
}

std::string Score::getName()
{
    return _name;
}

int Score::getScore() const
{
    return _score;
}
