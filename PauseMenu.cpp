#include "PauseMenu.h"


PauseMenu::PauseMenu()
{
	buildMenu();
	_selectedButtonIndex = 0;
	_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
}


PauseMenu::~PauseMenu()
{

}

void PauseMenu::buildMenu()
{
	_buttons.push_back(new Button{ "RESUME", 896 / 2, 200, 64, 32, PLAY });
	_buttons.push_back(new Button{ "QUIT", 896 / 2, 300, 64, 32, STARTMENU });

}

void PauseMenu::handleInput(InputHandler* input, SystemState& systemState)
{
	if (input->getPressed(SDL_SCANCODE_UP) && _selectedButtonIndex > 0)
	{
		_buttons.at(_selectedButtonIndex)->setButtonState(NOTSELECTED);
		_selectedButtonIndex--;
		_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
	}
	if (input->getPressed(SDL_SCANCODE_DOWN) && _selectedButtonIndex < _buttons.size() - 1)
	{
		_buttons.at(_selectedButtonIndex)->setButtonState(NOTSELECTED);
		_selectedButtonIndex++;
		_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
	}
	if (input->getPressed(SDL_SCANCODE_RETURN))
	{
		systemState = _buttons.at(_selectedButtonIndex)->getSystemState();
		_buttons.at(_selectedButtonIndex)->setButtonState(NOTSELECTED);
		_selectedButtonIndex = 0;
		_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
	}
}
