#include "MenuSystem.h"

MenuSystem::MenuSystem(InputHandler* ih, ResourceManager* rm, HighScore* hs, SDL_Renderer* renderer) : SystemModule{}, _input{ ih }, _rm{ rm }, _highscore{ hs }, _renderer{renderer}
{
	_startMenu = new StartMenu();
	_helpMenu = new HelpMenu();
	_highscoreMenu = new HighscoreMenu();
	_menuRenderer = new MenuRenderer(rm);
	_menuRenderer->loadContent();
	_highscoreMenuRenderer = new HighscoreMenuRenderer(rm);
	_highscoreMenuRenderer->loadContent();
}

MenuSystem::~MenuSystem()
{
  delete _input;
  delete _rm;
  delete _highscore;
}

void MenuSystem::run()
{
	handleInput();
	render();
}

void MenuSystem::handleInput()
{
	if (systemState == STARTMENU) _startMenu->handleInput(_input, systemState);
	else if (systemState == HIGHSCORE) _highscoreMenu->handleInput(_input, systemState);
	//else if (systemState == PAUSE) _pauseMenu->handleInput(_input);
	else if (systemState == HELP) _helpMenu->handleInput(_input, systemState);
	//else if (systemState == DEAD) _writeNameMEnu->handleInput(_input);
}

void MenuSystem::render()
{
	if (systemState == STARTMENU) _menuRenderer->render(_startMenu, _renderer);
	else if (systemState == HIGHSCORE) _highscoreMenuRenderer->render(_highscoreMenu, _renderer);
	//else if (systemState == PAUSE) _menuRenderer->render(_pauseMenu);
	else if (systemState == HELP) _menuRenderer->render(_helpMenu, _renderer);
	//else if (systemState == DEAD) _menuRenderer->render(_writeNameMenu);
}

SystemState MenuSystem::getState()
{
	return systemState;
}


