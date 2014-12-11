#include "Object.h"

#ifndef ITEM_H
#define ITEM_H

enum ItemType
{
    HealthType,
    SpeedBoostType,
    DoubleJumpType,
    GlideJumpType,
};

class Item : public Object
{
public:
    Item(int x, int y, int width, int height) : Object(x, y, width, height) {}

    ~Item() = default;

    Item* clone() const override;
    void updateLogic() override;
  
    ItemType getType();
    
protected:
    ItemType _type;    
};

#endif
