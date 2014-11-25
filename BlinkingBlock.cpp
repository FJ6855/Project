#include "BlinkingBlock.h"
#include <iostream>
void BlinkingBlock::updateLogic()
{
  _timer += 1;

  if (_timer >= _timeLimit)
    {
      _timer = 0;
      _visible = !_visible;
    }
}

bool BlinkingBlock::isVisible()
{
  return _visible;
}
