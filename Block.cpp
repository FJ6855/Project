#include "Block.h"

BlockType Block::getType()
{
    return _type;
}

void Block::setType(BlockType type)
{
    _type = type;
}

Block* Block::clone() const
{
    return new Block(*this);
}

void Block::updateLogic()
{

}
