#include "Object.cc";

enum itemType{type1};

Item : public Object
{
 public:
 Item(int width, int height, int x, int y, itemType type, float health) : _type{type}, _health{health}, Object(width, height, x, y){}

 itemType getType();
 float getHealth();
 void updateLogic();

 private:
  itemType _type;
  float _health;
}
