#include "WriteNameMenu.h"
#include <iostream>

WriteNameMenu::WriteNameMenu()
{
	buildMenu();
	_selectedButtonIndex = 0;
	_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
}


WriteNameMenu::~WriteNameMenu()
{

}

void WriteNameMenu::buildMenu()
{
	_buttons.push_back(new Button{ "ACCEPT", 200, 400, 64, 32, PLAY });

	_buttons.push_back(new Button{ "CANCEL", 400, 400, 64, 32, PLAY });

}

void WriteNameMenu::handleInput(InputHandler* input, SystemState& systemState)
{
	if ((input->getPressed(SDL_SCANCODE_LEFT) || input->getPressed(SDL_SCANCODE_A)) && _selectedButtonIndex > 0)
	{
		_buttons.at(_selectedButtonIndex)->setButtonState(NOTSELECTED);
		_selectedButtonIndex--;
		_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
	}
	if ((input->getPressed(SDL_SCANCODE_RIGHT) || input->getPressed(SDL_SCANCODE_D)) && _selectedButtonIndex < _buttons.size() - 1)
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
