#include "Object.h"

#ifndef BLOCK_H
#define BLOCK_H

enum BlockType
{
  NormalBlock1,
  BlinkingBlock1,
  BlinkingBlockInvisible1,
  SpeedBlockRight1,
  SpeedBlockLeft1,
};

class Block : public Object
{
 public:
 Block(int x, int y, int width, int height) : Object(x, y, width, height)
  {
    _type = BlockType::NormalBlock1;
  }

 Block(int x, int y, int width, int height, BlockType type) : Object(x, y, width, height), _type{type} {}
  
  BlockType getType();
  void updateLogic() override;
  
 protected:
  BlockType _type;
};

#endif
