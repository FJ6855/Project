#include "HighscoreMenu.h"

void HighscoreMenu::buildMenu()
{
    _buttons.push_back(new Button{ "BACK", 896 / 2, 400, 64, 32, STARTMENU });
}

void HighscoreMenu::handleInput(InputHandler* input, SystemState& systemState)
{
    if (input->getPressed(SDL_SCANCODE_RETURN) || input->getPressed(SDL_SCANCODE_SPACE))
    {
	systemState = _buttons.at(_selectedButtonIndex)->getSystemState();
	_selectedButtonIndex = 0;
    }
}
std::vector<Score*> HighscoreMenu::getScores()
{
    return _highscore->getScores();
}
