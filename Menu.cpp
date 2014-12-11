#include "Menu.h"

std::vector<Button*> Menu::getButtons()
{
    return _buttons;
}

void Menu::updateButtons(InputHandler* input, SystemState& systemState)
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
