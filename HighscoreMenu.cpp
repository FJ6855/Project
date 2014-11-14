#include "HighscoreMenu.h"
#include <iostream>

HighscoreMenu::HighscoreMenu()
{
	buildMenu();
	_selectedButtonIndex = 0;
	_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
}


HighscoreMenu::~HighscoreMenu()
{

}

void HighscoreMenu::buildMenu()
{
	_buttons.push_back(new Button{ "BACK", 400, 400, 64, 32, STARTMENU });
}

void HighscoreMenu::handleInput(InputHandler* input, SystemState& systemState)
{
	if (input->getPressed(SDL_SCANCODE_UP) && _selectedButtonIndex > 0)
	{
		_buttons.at(_selectedButtonIndex)->setButtonState(NOTSELECTED);
		_selectedButtonIndex--;
		_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);

		std::cout << "selected button is now " << _selectedButtonIndex << std::endl;
	}
	if (input->getPressed(SDL_SCANCODE_DOWN) && _selectedButtonIndex < _buttons.size() - 1)
	{
		_buttons.at(_selectedButtonIndex)->setButtonState(NOTSELECTED);
		_selectedButtonIndex++;
		_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);

		std::cout << "selected button is now " << _selectedButtonIndex << std::endl;
	}
	if (input->getPressed(SDL_SCANCODE_RETURN))
	{
		systemState = _buttons.at(_selectedButtonIndex)->getSystemState();
		_selectedButtonIndex = 0;
		if (systemState == STARTMENU) std::cout << "State is now STARTMENU" << std::endl;

	}

}

