#include "MenuRenderer.h"

MenuRenderer::~MenuRenderer()
{

}

void MenuRenderer::loadContent()
{
  _buttonRenderer->loadContent();
  //Load textures into texture vector

}

void MenuRenderer::render(Menu* menu, SDL_Renderer* renderer)
{
  std::vector<Button*> v = menu->getButtons();
  for (int i = 0; i < v.size(); ++i)
    _buttonRenderer->render(v.at(i), renderer);
}
