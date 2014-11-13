#include "MenuSystem.h"

MenuSystem::~MenuSystem()
{
  delete _input;
  delete _rm;
  delete _highscore;
}

