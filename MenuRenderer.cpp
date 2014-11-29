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
		_menuBackground->render(renderer, 0, 0, 896, 512);
		_startMenuText->render(renderer, 896 / 2 - _startMenuText->getWidth() / 2, 0, _startMenuText->getWidth(), _startMenuText->getHeight());
	}
	else if (dynamic_cast<HelpMenu*>(menu))
	{
		_helpMenuBackground->render(renderer, 0, 0, 896, 512);
		_helpMenuText->render(renderer, 896 / 2 - _helpMenuText->getWidth() / 2, 0, _helpMenuText->getWidth(), _helpMenuText->getHeight());
	}
	else if (dynamic_cast<PauseMenu*>(menu))
	{
		_pausedText->render(renderer, 896 / 2 - _pausedText->getWidth() / 2, 100, _pausedText->getWidth(), _pausedText->getHeight());
	}
	else if (dynamic_cast<WriteNameMenu*>(menu))
	{
		_menuBackground->render(renderer, 0, 0, 896, 512);
		_newHighscoreText->render(renderer, 896 / 2 - _newHighscoreText->getWidth() / 2, 0, _newHighscoreText->getWidth(), _newHighscoreText->getHeight());

		_writeNameInscruction->render(renderer, 896 / 2 - _writeNameInscruction->getWidth() / 2, 170, _writeNameInscruction->getWidth(), _writeNameInscruction->getHeight());
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
