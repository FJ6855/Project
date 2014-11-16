#include "StartMenu.h"

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
	_buttons.push_back(new Button{"PLAY", 896/2, 100, 64, 32, PLAY});
	_buttons.push_back(new Button{ "HELP", 896 / 2, 200, 64, 32, HELP });
	_buttons.push_back(new Button{ "HIGHSCORE", 896 / 2, 300, 64, 32, HIGHSCORE });
	_buttons.push_back(new Button{ "QUIT", 896 / 2, 400, 64, 32, QUIT });
}

void StartMenu::handleInput(InputHandler* input, SystemState& systemState)
{
  if(input->getPressed(SDL_SCANCODE_UP) && _selectedButtonIndex > 0)
    {
      _buttons.at(_selectedButtonIndex)->setButtonState(NOTSELECTED);
      _selectedButtonIndex--;
      _buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
    }
  if(input->getPressed(SDL_SCANCODE_DOWN) && _selectedButtonIndex < _buttons.size()-1)
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
	  if (systemState == QUIT)
	  {
		  SDL_Event e;
		  e.type = SDL_QUIT;
		  SDL_PushEvent(&e);
	  }
  }
}
