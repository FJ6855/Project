#include "PowerUp.h"

#ifndef GLIDE_JUMP_H
#define GLIDE_JUMP_H

class GlideJump : public PowerUp
{
public:
    GlideJump(int x, int y, int width, int height, float timer) : PowerUp(x, y, width, height, timer)
    {
	_type = ItemType::GlideJumpType;
  
	_glideTimer = 1000;
    }

    ~GlideJump() = default;

    void updateLogic() override;
    void updateLogic(Player* player) override;

private:
    int _timer;
    int _glideTimer;
};

#endif
