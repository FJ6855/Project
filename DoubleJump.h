#include "PowerUp.h"

#ifndef DOUBLE_JUMP_H
#define DOUBLE_JUMP_H

class DoubleJump : public PowerUp
{
 public:
 DoubleJump(int x, int y, int width, int height, float timer) : PowerUp(x, y, width, height, timer)
  {
    _type = ItemType::DoubleJumpType;
    _numberOfJumps = 0;
  }

  void updateLogic() override;
  void updateLogic(Player* player) override;

 private:
  int _timer;
  int _numberOfJumps;
};

#endif
