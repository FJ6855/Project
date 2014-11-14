#include "InputHandler.h"

InputHandler::InputHandler()
{
  _quit = false;
  for(int i{}; i < 300; ++i)
    _keysDown[i] = false;

  for(int i{}; i < 300; ++i)
    _keysPressed[i] = false;
}

void InputHandler::handleEvent(SDL_Event& e)
{
 if(e.type == SDL_KEYDOWN)
  {
    if(!_keysDown[e.key.keysym.scancode])
      { 
	_keysPressed[e.key.keysym.scancode] = true;
      }
    _keysDown[e.key.keysym.scancode] = true;
  }
  else if(e.type == SDL_KEYUP)
  {
      _keysDown[e.key.keysym.scancode] = false;
  }
}

bool InputHandler::getKey(int scancode)
{
  return _keysDown[scancode];
}

bool InputHandler::getPressed(int scancode)
{
  return _keysPressed[scancode];
}

void InputHandler::update() 
{
  for(int i{}; i < 300; ++i)
    _keysPressed[i] = false;

  SDL_Event e;
  while (SDL_PollEvent(&e) != 0)
    {
      if (e.type == SDL_QUIT)
		_quit = true;
      else
		handleEvent(e);
    }
}

bool InputHandler::isQuit()
{
  return _quit;
}
