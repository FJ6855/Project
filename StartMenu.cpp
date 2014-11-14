#include "StartMenu.h"

#include <iostream>

StartMenu::StartMenu()
{
	buildMenu();
	_selectedButtonIndex = 0;
	_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
}


StartMenu::~StartMenu()
{

}

void StartMenu::buildMenu()
{
	_buttons.push_back(new Button{"PLAY", 400, 100, 64, 32, PLAY});
	_buttons.push_back(new Button{"HELP", 400, 200, 64, 32, HELP});
	_buttons.push_back(new Button{"HIGHSCORE", 400, 300, 64, 32, HIGHSCORE});
	_buttons.push_back(new Button{"QUIT", 400, 400, 64, 32, QUIT});
}

void StartMenu::handleInput(InputHandler* input, SystemState& systemState)
{
  if(input->getPressed(SDL_SCANCODE_UP) && _selectedButtonIndex > 0)
    {
      _buttons.at(_selectedButtonIndex)->setButtonState(NOTSELECTED);
      _selectedButtonIndex--;
      _buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);

	  std::cout << "selected button is now " << _selectedButtonIndex << std::endl;
    }
  if(input->getPressed(SDL_SCANCODE_DOWN) && _selectedButtonIndex < _buttons.size()-1)
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
	  if (systemState == QUIT)
	  {
		  SDL_Event e;
		  e.type = SDL_QUIT;
		  SDL_PushEvent(&e);
	  }
	  if(systemState == PLAY) std::cout << "State is now PLAY" << std::endl;
	  if (systemState == HELP) std::cout << "State is now HELP" << std::endl;
	  if (systemState == HIGHSCORE) std::cout << "State is now HIGHSCORE" << std::endl;
	  if (systemState == QUIT) std::cout << "State is now QUIT" << std::endl;
  }

}
