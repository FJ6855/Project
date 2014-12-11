#include "Block.h"

#ifndef MOVING_BLOCK_H
#define MOVING_BLOCK_H

class MovingBlock : public Block
{
public:
    MovingBlock(int x, int y, int width, int height, float speed, int interval) : Block(x, y, width, height), _speed{speed}, _interval(interval)
    {
	_movingX = 0;
    }

    ~MovingBlock() = default;
    
    MovingBlock* clone() const override;
    void updateLogic() override;

    int getMovingX();
    float getSpeed();

private:
    int _movingX;
    int _interval;
    float _speed;
};

#endif
