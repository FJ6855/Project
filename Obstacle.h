#include "Object.cc";

enum ObstacleType{mine};

class Obstacle : public Object
{
 public:
 Obstacle(int width, int height, int x, int y, ObstacleType type, float damage) : _type{type},_damage{damage}, Object(height,width,x,y){}

 ObstacleType getType();
 float getDamage();
 void updateLogic();

 private:
  float _damage;
  ObstacleType _type;
}
