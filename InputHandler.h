#include <SDL2/SDL.h>

#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

class InputHandler
{
public:
    InputHandler()
    {	
	_quit = false;

	for(int i{}; i < 300; ++i)
	    _keysDown[i] = false;

	for(int i{}; i < 300; ++i)
	    _keysPressed[i] = false;
    }
    
    ~InputHandler() = default;
    
    void handleEvent(SDL_Event& e);

    bool getKey(int scancode);
    bool getPressed(int scancode);

    void update();

    bool isQuit();

private:
    bool _quit;
    bool _keysDown[300];
    bool _keysPressed[300];
};

#endif
