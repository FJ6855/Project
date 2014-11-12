#include "Object.cc";

enum obstacleType{mine};

Obstacle : public Object
{
 public:
 Obstacle(int width, int height, int x, int y, objectType type, float damage) : _type{type},_damage{damage}, Object(height,width,x,y){}

 obstacleType getType();
 float getDamage();

 private:
  float _damage;
  objectType _type;
}
