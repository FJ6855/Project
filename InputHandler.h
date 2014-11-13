#include <SDL2/SDL.h>

#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

class InputHandler
{
 public:
  InputHandler();
  void handleEvent(SDL_Event& e);
  bool getKey(int scancode);
  bool getPressed(int scancode);
  void update();
  bool isQuit();

 protected:

 private:
  bool _quit;
  bool _keysDown[300];
  bool _keysPressed[300];
};

#endif
