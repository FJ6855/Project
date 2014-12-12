#include "PauseMenu.h"

void PauseMenu::buildMenu()
{
    _buttons.push_back(new Button{ "RESUME", 896 / 2, 150, 64, 32, PLAY });
    _buttons.push_back(new Button{ "HELP", 896 / 2, 250, 64, 32, HELP });
    _buttons.push_back(new Button{ "QUIT", 896 / 2, 350, 64, 32, STARTMENU });

    _buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
}

void PauseMenu::handleInput(InputHandler* input, SystemState& systemState, SystemState& lastSystemState)
{
    Menu::updateButtons(input, systemState, lastSystemState);
}
