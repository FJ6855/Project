#include "Menu.h"

#ifndef STARTMENU_H
#define STARTMENU_H

class StartMenu : public Menu
{
public:
    StartMenu()
    {	
	buildMenu();
	_selectedButtonIndex = 0;
	_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
    }

    ~StartMenu() = default;
	
    void handleInput(InputHandler* input, SystemState& systemState) override;

private:
    void buildMenu();
};

#endif

