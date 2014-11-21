#include "Object.h"

#ifndef ITEM_H
#define ITEM_H

enum ItemType
{
  ItemType1
};

class Item : public Object
{
 public:
 Item(int x, int y, int width, int height, ItemType type, float health) : _type{type}, _health{health}, Object(x, y, width, height){}

 ItemType getType();
 float getHealth();
 void updateLogic();

 private:
  ItemType _type;
  float _health;
};

#endif
