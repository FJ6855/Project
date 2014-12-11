#include "BlinkingBlock.h"

BlinkingBlock* BlinkingBlock::clone() const
{
    return new BlinkingBlock(*this);
}

void BlinkingBlock::updateLogic()
{
    _timer += 1;

    if (_timer >= _timeLimit)
    {
	_timer = 0;
	_visible = !_visible;
    }

    if (_visible)
	_type = BlockType::BlinkingBlock1;
    else
	_type = BlockType::BlinkingBlockInvisible1;
}

bool BlinkingBlock::isVisible()
{
    return _visible;
}
