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
  }
  ~MenuRenderer();
  
  void loadContent() override;
  void render(Menu* menu, SDL_Renderer* renderer);
 private:

  ButtonRenderer* _buttonRenderer;
};



#endif
