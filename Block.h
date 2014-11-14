#include "Object.h"

enum BlockType
{
  type1
};

#ifndef BLOCK_H
#define BLOCK_H

class Block : public Object
{
 public:
 Block(int width, int height, int x, int y, BlockType type) : _type{type}, Object(width, height, x, y) {}

 BlockType getType();
 void updateLogic();

 private:
  BlockType _type;
};

#endif
