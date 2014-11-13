#ifndef MENUSYSTEM_H
#define MENUSYSTEM_H

enum MenuState
{
  PauseMenu


};

class MenuSystem
{
 public:
 MenuSystem(InputHandler* ih, ResourceManager* rm, HighScore* hs)
   : _input{ih}, _rm{rm}, _highscore{hs} {}
  ~MenuSystem();

  void handleInput(

 private:
  InputHandler* _input;
  ResourceManager* _rm;
  HighScore* _highscore;

  //StartMenu* _startMenu;
  //HighscoreMenu* _highscoreMenu;
  //PauseMenu* _pauseMenu;
  //writeNameMenu* _writeNameMenu;

  //MenuRenderer* _menuRenderer;
  //HighscoreMenuRenderer _highscoreMenuRenderer;
};



#endif
