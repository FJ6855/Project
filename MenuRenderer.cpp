#include "MenuRenderer.h"
#include "StartMenu.h"
#include "HelpMenu.h"
#include "HighscoreMenu.h"
#include "PauseMenu.h"

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
	if (dynamic_cast<StartMenu*>(menu))
	{
		_startMenuBackground->render(renderer, 0, 0, 896, 512);
	}
	else if (dynamic_cast<HelpMenu*>(menu))
	{
		_helpMenuBackground->render(renderer, 0, 0, 896, 512);
	}
	else if (dynamic_cast<HighscoreMenu*>(menu))
	{
		_highscoreMenuBackground->render(renderer, 0, 0, 896, 512);
	}
	else if (dynamic_cast<PauseMenu*>(menu))
	{
		_pauseMenuBackground->render(renderer, 0, 0, 896, 512);
	}

  std::vector<Button*> v = menu->getButtons();
  for (int i = 0; i < v.size(); ++i)
    _buttonRenderer->render(v.at(i), renderer);
}
