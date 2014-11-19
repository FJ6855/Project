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

#ifndef MENUSYSTEM_H
#define MENUSYSTEM_H

class MenuSystem : public SystemModule
{
 public:
	 MenuSystem(InputHandler* ih, ResourceManager* rm, HighScore* hs, SDL_Renderer* renderer);
  ~MenuSystem();

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
  //WriteNameMenu* _writeNameMenu;
  HelpMenu* _helpMenu;

  MenuRenderer* _menuRenderer;
  HighscoreMenuRenderer* _highscoreMenuRenderer;
};



#endif
