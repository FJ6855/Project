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
    _pauseMenuBackground = rm->loadTexture("pauseMenuBackground");
    _writeNameMenuBackground = rm->loadTexture("writeNameMenuBackground");
  }
  ~MenuRenderer();
  
  void loadContent() override;
  void render(Menu* menu, SDL_Renderer* renderer);

 protected:
   ButtonRenderer* _buttonRenderer;

 private:
  Texture* _startMenuBackground;
  Texture* _helpMenuBackground;
  Texture* _pauseMenuBackground;
  Texture* _writeNameMenuBackground;

  Texture* _nameText;
};

#endif
