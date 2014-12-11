#include "PauseMenu.h"

void PauseMenu::buildMenu()
{
    _buttons.push_back(new Button{ "RESUME", 896 / 2, 200, 64, 32, PLAY });
    _buttons.push_back(new Button{ "QUIT", 896 / 2, 300, 64, 32, STARTMENU });
}

void PauseMenu::handleInput(InputHandler* input, SystemState& systemState)
{
    if ((input->getPressed(SDL_SCANCODE_UP) || input->getPressed(SDL_SCANCODE_W)) && _selectedButtonIndex > 0)
    {
	_buttons.at(_selectedButtonIndex)->setButtonState(NOTSELECTED);
	_selectedButtonIndex--;
	_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
    }

    if ((input->getPressed(SDL_SCANCODE_DOWN) || input->getPressed(SDL_SCANCODE_S)) && _selectedButtonIndex < _buttons.size() - 1)
    {
	_buttons.at(_selectedButtonIndex)->setButtonState(NOTSELECTED);
	_selectedButtonIndex++;
	_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
    }

    if (input->getPressed(SDL_SCANCODE_RETURN) || input->getPressed(SDL_SCANCODE_SPACE))
    {
	systemState = _buttons.at(_selectedButtonIndex)->getSystemState();
	_buttons.at(_selectedButtonIndex)->setButtonState(NOTSELECTED);
	_selectedButtonIndex = 0;
	_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
    }
}
