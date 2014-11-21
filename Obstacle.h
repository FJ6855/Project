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
	Obstacle(int x, int y, int width, int height, ObstacleType type, float damage) : _type{ type }, _damage{ damage }, Object(x, y, width, height){}

	ObstacleType getType();
	float getDamage();
	void updateLogic();

private:
	ObstacleType _type;
	float _damage;
};

#endif
