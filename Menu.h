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
    ~Menu()
    {
	for (Button* b : _buttons)
	    delete b;
    }

    virtual void handleInput(InputHandler* input, SystemState& systemState) = 0;
    void updateButtons(InputHandler* input, SystemState& systemState);

    std::vector<Button*> getButtons();

protected:
    Menu() : _selectedButtonIndex{0} {}
    Menu(const Menu&) = default;

    std::vector<Button*> _buttons;
    int _selectedButtonIndex;

private:
    virtual void buildMenu() = 0;
};

#endif
