#include "PowerUp.h"

#ifndef SPEED_BOOST_H
#define SPEED_BOOST_H

class SpeedBoost : public PowerUp
{
public:
    SpeedBoost(int x, int y, int width, int height, float timer, int speed) : PowerUp(x, y, width, height, timer), _speed{speed}
    {
	_type = ItemType::SpeedBoostType;
    }

    ~SpeedBoost() = default;

    void updateLogic() override;
    void updateLogic(Player* player) override;

private:
    int _speed;
};

#endif
