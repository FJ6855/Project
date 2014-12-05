#include "WriteNameMenu.h"
#include <iostream>

WriteNameMenu::WriteNameMenu(HighScore* hs)
{
        _highscore = hs;
	buildMenu();
	_selectedButtonIndex = 0;
	_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
	_name = "";
}


WriteNameMenu::~WriteNameMenu()
{}

void WriteNameMenu::buildMenu()
{
        _buttons.push_back(new Button{"ACCEPT", 896/2, 400, 64, 32, PLAY });
}

void WriteNameMenu::handleInput(InputHandler* input, SystemState& systemState)
{
  if (input->getPressed(SDL_SCANCODE_RETURN) && _name.size() > 0)
	{
	  systemState = _buttons.at(_selectedButtonIndex)->getSystemState();
	  _selectedButtonIndex = 0;
	  _highscore->setCurrentName(_name);
	  _highscore->newHighScoreSet();
	  _name = "";
	}

	
	for(int i = 4; i < 29; ++i)
	{
	  if(input->getPressed(i) && _name.size() < 15)
	     {
	       _name += i+61;
	     }
	}

	if(input->getPressed(SDL_SCANCODE_SPACE) && _name.size() < 15)
	{
	    _name += " ";
    }

	if(_name.size() > 0 && input->getPressed(SDL_SCANCODE_BACKSPACE))
	   _name.pop_back(); 
	
}


std::string WriteNameMenu::getName()
{
  return _name;
}
