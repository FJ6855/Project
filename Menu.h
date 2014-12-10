#include <vector>

#include "Button.h"
#include "InputHandler.h"
#include "SystemModule.h"
#include "Texture.h"

#ifndef MENU_H
#define MENU_H

class Menu
{
public:
    Menu()
    {
    }

    ~Menu()
    {
	for (Button* b : _buttons)
	    delete b;
    }

    virtual void handleInput(InputHandler* input, SystemState& systemState) = 0;

    std::vector<Button*> getButtons();
    Texture* getMenuBackground();

protected:
    std::vector<Button*> _buttons;
    int _selectedButtonIndex;
};

#endif
