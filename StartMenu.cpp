#include "StartMenu.h"

void StartMenu::buildMenu()
{
    _buttons.push_back(new Button{"PLAY", 896/2, 100, 64, 32, START_GAME});
    _buttons.push_back(new Button{ "HELP", 896 / 2, 200, 64, 32, HELP });
    _buttons.push_back(new Button{ "HIGHSCORE", 896 / 2, 300, 64, 32, HIGHSCORE });
    _buttons.push_back(new Button{ "QUIT", 896 / 2, 400, 64, 32, QUIT });

    _buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
}

void StartMenu::handleInput(InputHandler* input, SystemState& systemState)
{
    Menu::updateButtons(input, systemState);

    if (systemState == QUIT)
    {
	SDL_Event e;
	e.type = SDL_QUIT;
	SDL_PushEvent(&e);
    }
}
