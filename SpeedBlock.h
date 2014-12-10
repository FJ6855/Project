#include "Block.h"

#ifndef SPEED_BLOCK_H
#define SPEED_BLOCK_H

class SpeedBlock : public Block
{
public:
    SpeedBlock(int x, int y, int width, int height, BlockType type, int speedFactor) : Block(x, y, width, height, type), _speedFactor{speedFactor} {}
  
    int getSpeedFactor();
  
private:
    int _speedFactor;
};

#endif
