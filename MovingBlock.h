#include "Block.h"

#ifndef MOVING_BLOCK_H
#define MOVING_BLOCK_H

class MovingBlock : public Block
{
 public:
 MovingBlock(int x, int y, int width, int height, BlockType type, float speed) : Block(x, y, width, height, type), _speed{speed}
    {
    }
 
  void updateLogic();

 private:
  float _speed;
};

#endif
