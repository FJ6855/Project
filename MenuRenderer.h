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
    _writeNameMenuBackground = rm->loadTexture("pauseMenuBackground"); //behövs en egen kanske
  }
  ~MenuRenderer();
  
  void loadContent() override;
  void render(Menu* menu, SDL_Renderer* renderer);

 private:
  Texture* _startMenuBackground;
  Texture* _helpMenuBackground;
  Texture* _highscoreMenuBackground;
  Texture* _pauseMenuBackground;
  Texture* _writeNameMenuBackground;

  ButtonRenderer* _buttonRenderer;
};

#endif
