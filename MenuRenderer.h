#include "Renderer.h"
#include "ResourceManager.h"
#include "ButtonRenderer.h"
#include "Menu.h"

#ifndef MENURENDERER_H
#define MENURENDERER_H

class MenuRenderer : public Renderer
{
 public:
 MenuRenderer(ResourceManager* rm) : Renderer{rm} 
  {
    _buttonRenderer = new ButtonRenderer(rm);
    _startMenuBackground = rm->loadTexture("startMenuBackground");
    _helpMenuBackground = rm->loadTexture("helpMenuBackground");
    _highscoreMenuBackground = rm->loadTexture("highscoreMenuBackground");
    _pauseMenuBackground = rm->loadTexture("pauseMenuBackground");
  }
  ~MenuRenderer();
  
  void loadContent() override;
  void render(Menu* menu, SDL_Renderer* renderer);

 private:
  Texture* _startMenuBackground;
  Texture* _helpMenuBackground;
  Texture* _highscoreMenuBackground;
  Texture* _pauseMenuBackground;

  ButtonRenderer* _buttonRenderer;
};



#endif
/*
class PlayerRenderer : public Renderer
{
public:
PlayerRenderer(ResourceManager* rm) : Renderer{rm} 
{
_playerTexture = rm->loadTexture("blockk");
}
~PlayerRenderer();

void loadContent() override;
void render(Player* player, SDL_Renderer* renderer);

private:
Texture* _playerTexture;
};


#endif*/
