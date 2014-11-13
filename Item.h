#include "Object.cc";

enum ItemType{type1};

class Item : public Object
{
 public:
 Item(int width, int height, int x, int y, ItemType type, float health) : _type{type}, _health{health}, Object(width, height, x, y){}

 ItemType getType();
 float getHealth();
 void updateLogic();

 private:
  ItemType _type;
  float _health;
}
