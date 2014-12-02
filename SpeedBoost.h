#include "Item.h"

#ifndef SPEED_BOOST_H
#define SPEED_BOOST_H

class SpeedBoost : public Item
{
 public:
 SpeedBoost(int x, int y, int width, int height, int speed, int timer) : Item(x, y, width, height), _speed{speed}, _timer{timer}
  {
    _type = ItemType::SpeedBoostType;
  }

  int getSpeed();
  int getTimer();
  void updateLogic() override;

 private:
  int _speed;
  int _timer;
};

#endif
