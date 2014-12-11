#include "Object.h"

#ifndef OBSTACLE_H
#define OBSTACLE_H

enum ObstacleType
{
    ObstacleType1
};

class Obstacle : public Object
{
public:
    Obstacle(int x, int y, int width, int height, float damage) : Object(x, y, width, height), _damage{ damage }
    {
	_type = ObstacleType::ObstacleType1;
    }

    ~Obstacle() = default;

    Obstacle* clone() const override;
    void updateLogic();

    ObstacleType getType();
    float getDamage();

private:
    ObstacleType _type;
    float _damage;
};

#endif
