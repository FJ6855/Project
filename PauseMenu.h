#include "Menu.h"

#ifndef PAUSEMENU_H
#define PAUSEMENU_H

class PauseMenu : public Menu
{
public:
    PauseMenu()
    {
	buildMenu();
	_selectedButtonIndex = 0;
	_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
    }
    
    ~PauseMenu() = default;

    void handleInput(InputHandler* input, SystemState& systemState) override;

private:
    void buildMenu();
};

#endif

