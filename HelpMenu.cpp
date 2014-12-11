#include "HelpMenu.h"

void HelpMenu::buildMenu()
{
    _buttons.push_back(new Button{ "BACK", 896 / 2, 425, 64, 32, STARTMENU });
    
    _buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
}

void HelpMenu::handleInput(InputHandler* input, SystemState& systemState)
{
    Menu::updateButtons(input, systemState);
}
