#include "Obstacle.h"

Obstacle* Obstacle::clone() const
{
    return new Obstacle(*this);
}

void Obstacle::updateLogic()
{

}

ObstacleType Obstacle::getType()
{
    return _type;
}

float Obstacle::getDamage()
{
    return _damage;
}
