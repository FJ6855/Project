#include "InputHandler.h"
#include "ResourceManager.h"
#include "HighScore.h"
#include "SystemModule.h"
#include "StartMenu.h"
#include "MenuRenderer.h"
#include "HelpMenu.h"
#include "HighscoreMenu.h"
#include "HighscoreMenuRenderer.h"
#include "PauseMenu.h"
#include "WriteNameMenu.h"

#ifndef MENUSYSTEM_H
#define MENUSYSTEM_H

class MenuSystem : public SystemModule
{
public:
    MenuSystem(InputHandler* ih, ResourceManager* rm, HighScore* hs, SDL_Renderer* renderer) : SystemModule{}, _input{ih}, _rm{rm}, _highscore{hs}, _renderer{renderer}
    {
	_startMenu = new StartMenu();
	_helpMenu = new HelpMenu();
	_highscoreMenu = new HighscoreMenu(_highscore);
	_pauseMenu = new PauseMenu();
	_writeNameMenu = new WriteNameMenu(_highscore);
	_menuRenderer = new MenuRenderer(rm);
	_menuRenderer->loadContent();
	_highscoreMenuRenderer = new HighscoreMenuRenderer(rm);
	_highscoreMenuRenderer->loadContent();
    }

    ~MenuSystem()
    {
	delete _startMenu;
	delete _helpMenu;
	delete _highscoreMenu;
	delete _pauseMenu;
	delete _writeNameMenu;
	delete _menuRenderer;
	delete _highscoreMenuRenderer;
    }

    void run();
    SystemState getState();
    void handleInput();
    void render();

private:
    InputHandler* _input;
    ResourceManager* _rm;
    HighScore* _highscore;
    SDL_Renderer* _renderer;

    void loadContent();

    StartMenu* _startMenu;
    HighscoreMenu* _highscoreMenu;
    PauseMenu* _pauseMenu;
    WriteNameMenu* _writeNameMenu;
    HelpMenu* _helpMenu;

    MenuRenderer* _menuRenderer;
    HighscoreMenuRenderer* _highscoreMenuRenderer;
};

#endif
