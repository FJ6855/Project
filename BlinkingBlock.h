#include "Block.h"

#ifndef BLINKING_BLOCK_H
#define BLINKING_BLOCK_H

class BlinkingBlock : public Block
{
public:
    BlinkingBlock(int x, int y, int width, int height, int timeLimit) : Block(x, y, width, height), _timeLimit{timeLimit}
    {
	_timer = 0;
	_visible = true;
	_type = BlockType::BlinkingBlock1;
    }

    ~BlinkingBlock() = default;
 
    void updateLogic() override;
    bool isVisible();

private:
    int _timer;
    int _timeLimit; 
    bool _visible;
};

#endif
