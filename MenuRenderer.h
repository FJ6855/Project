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

	_menuBackground = rm->loadTexture("menuBackground");
	_helpMenuBackground = rm->loadTexture("helpMenuBackground");

	_pausedText = rm->loadTexture("PausedText");
	_startMenuText = rm->loadTexture("startMenuText");
	_newHighscoreText = rm->loadTexture("newHighscoreText");
	_helpMenuText = rm->loadTexture("helpMenuText");
	_nameText = rm->loadTexture(" ", SDL_Color{ 255, 255, 255 });

	_writeNameInscruction = _rm->loadTexture("Please type your name ", SDL_Color{ 255, 255, 255 });
    }

    ~MenuRenderer()
    {
	delete _buttonRenderer;

	delete _menuBackground;
	delete _helpMenuBackground;

	delete _pausedText;
	delete _startMenuText;
	delete _newHighscoreText;
	delete _helpMenuText;

	delete _nameText;
	delete _writeNameInscruction;
    }
  
    void loadContent() override;
    void render(Menu* menu, SDL_Renderer* renderer);

protected:
    ButtonRenderer* _buttonRenderer;

private:
    Texture* _menuBackground;
    Texture* _helpMenuBackground;

    Texture* _pausedText;
    Texture* _startMenuText;
    Texture* _newHighscoreText;
    Texture* _helpMenuText;

    //For writeNameMenu
    Texture* _nameText;
    Texture* _writeNameInscruction;
};

#endif
