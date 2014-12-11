#include "Item.h"

ItemType Item::getType()
{
    return _type;
}

void Item::updateLogic()
{

}

Item* Item::clone() const
{
    return new Item(*this);
}
