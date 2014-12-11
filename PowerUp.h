#include "Item.h"

#ifndef POWER_UP_H
#define POWER_UP_H

class Player;

class PowerUp : public Item
{
public:
    PowerUp(int x, int y, int width, int height, float timer) : Item(x, y, width, height), _timer{timer} {}
    
    ~PowerUp() = default;

    PowerUp* clone() const override = 0;
    void updateLogic() override;
    virtual void updateLogic(Player* player) = 0;
    
    bool isActive();

    float getTimer();
    void setTimer(float timer);

private:
    float _timer;
};

#endif
