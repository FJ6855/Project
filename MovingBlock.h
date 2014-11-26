#include "Block.h"

#include <SDL2/SDL.h>

#ifndef MOVING_BLOCK_H
#define MOVING_BLOCK_H

class MovingBlock : public Block
{
 public:
 MovingBlock(int x, int y, int width, int height, BlockType type, float speed, int interval) : Block(x, y, width, height, type), _speed{speed}, _interval(interval)
    {
      _movingX = 0;
      _time = SDL_GetTicks();
      _updates = 0;
    }

    int getMovingX();

  void updateLogic();

 private:
  int _movingX;
  int _interval;
  float _speed;
  int _time;
  int _updates;
};

#endif
