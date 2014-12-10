#include "Menu.h"
#include "InputHandler.h"

#ifndef HELPMENU_H
#define HELPMENU_H

class HelpMenu : public Menu
{
public:
    HelpMenu()
    {
	buildMenu();
	_selectedButtonIndex = 0;
	_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
    }

    ~HelpMenu() = default;

    void handleInput(InputHandler* input, SystemState& systemState) override;

private:
    void buildMenu();
};

#endif
