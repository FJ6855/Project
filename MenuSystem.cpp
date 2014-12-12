#include "MenuSystem.h"

void MenuSystem::run()
{
    handleInput();
    render();
}

void MenuSystem::handleInput()
{
    if (systemState == STARTMENU) _startMenu->handleInput(_input, systemState, lastSystemState);
    else if (systemState == HIGHSCORE) _highscoreMenu->handleInput(_input, systemState, lastSystemState);
    else if (systemState == PAUSE) _pauseMenu->handleInput(_input, systemState, lastSystemState);
    else if (systemState == HELP) _helpMenu->handleInput(_input, systemState, lastSystemState);
    else if (systemState == WRITENAMEMENU) _writeNameMenu->handleInput(_input, systemState, lastSystemState);
}

void MenuSystem::render()
{
    if (systemState == STARTMENU) _menuRenderer->render(_startMenu, _renderer);
    else if (systemState == HIGHSCORE) _highscoreMenuRenderer->render(_highscoreMenu, _renderer);
    else if (systemState == PAUSE) _menuRenderer->render(_pauseMenu, _renderer);
    else if (systemState == HELP) _menuRenderer->render(_helpMenu, _renderer);
    else if (systemState == WRITENAMEMENU) _menuRenderer->render(_writeNameMenu, _renderer);
}


