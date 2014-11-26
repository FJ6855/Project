#include "Object.h"

#ifndef BLOCK_H
#define BLOCK_H

enum BlockType
{
  BlockType1,
  BlinkingBlock1,
  BlinkingBlockInvisible1,
  SpeedBlock1
};

class Block : public Object
{
 public:
 Block(int x, int y, int width, int height, BlockType type) : Object(x, y, width, height), _type{type} 
  {}
  
  BlockType getType();
  void updateLogic() override;
  
 private:
  BlockType _type;
};

#endif
