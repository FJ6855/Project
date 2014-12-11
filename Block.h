#include "Object.h"

#ifndef BLOCK_H
#define BLOCK_H

enum BlockType
{
    NormalBlock0,
    NormalBlock1,
    NormalBlock2,
    NormalBlock3,
    NormalBlock4,
    NormalBlock5,
    NormalBlock6,
    NormalBlock7,
    NormalBlock8,
    NormalBlock9,
    NormalBlock10,
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
    
    Block(const Block&) = default;

    ~Block() = default;

    Block* clone() const override;
    void updateLogic() override;
  
    BlockType getType();
    void setType(BlockType type);
  
protected:
    BlockType _type;
};

#endif
