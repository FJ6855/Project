#include "MenuRenderer.h"
#include "StartMenu.h"
#include "HelpMenu.h"
#include "HighscoreMenu.h"
#include "PauseMenu.h"
#include "WriteNameMenu.h"

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
	else if (dynamic_cast<PauseMenu*>(menu))
	{
		_pauseMenuBackground->render(renderer, 0, 0, 896, 512);
	}
	else if (dynamic_cast<WriteNameMenu*>(menu))
	{
		_writeNameMenuBackground->render(renderer, 0, 0, 896, 512);
		WriteNameMenu* writeNameMenu = dynamic_cast<WriteNameMenu*>(menu);
	        if(writeNameMenu->getName().size() > 0) 
		  {
		    _nameText = _rm->loadTexture(writeNameMenu->getName(), SDL_Color{255, 255, 255});
		    _nameText->render(renderer, 448 - _nameText->getWidth()/2, 200, _nameText->getWidth(), _nameText->getHeight());
		  }
	}

  std::vector<Button*> v = menu->getButtons();
  for (int i = 0; i < v.size(); ++i)
    _buttonRenderer->render(v.at(i), renderer);
}
