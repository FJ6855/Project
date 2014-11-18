#include "HelpMenu.h"
#include <iostream>

HelpMenu::HelpMenu()
{
	buildMenu();
	_selectedButtonIndex = 0;
	_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
}


HelpMenu::~HelpMenu()
{

}


void HelpMenu::buildMenu()
{
	_buttons.push_back(new Button{ "BACK", 896 / 2, 400, 64, 32, STARTMENU });
}

void HelpMenu::handleInput(InputHandler* input, SystemState& systemState)
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
		_selectedButtonIndex = 0;
	}

}
