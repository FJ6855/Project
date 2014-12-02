#include "Item.h"

#ifndef HEALTH_H
#define HEALTH_H

class Health : public Item
{
  public:
  Health(int x, int y, int width, int height, float health) : Item{x, y, width, height}, _health{health} 
  {
    _type = ItemType::HealthType;
  }
    
    float getHealth();
    void updateLogic() override;

  private:
    float _health;
};

#endif
