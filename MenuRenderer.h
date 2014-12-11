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

	loadContent();
    }

    ~MenuRenderer()
    {
	delete _buttonRenderer;
	_buttonRenderer = nullptr;

	delete _menuBackground;
	_menuBackground = nullptr;
	delete _helpMenuBackground;
	_helpMenuBackground = nullptr;

	delete _pausedText;
	_pausedText = nullptr;
	delete _startMenuText;
	_startMenuText = nullptr;
	delete _newHighscoreText;
	_newHighscoreText = nullptr;
	delete _helpMenuText;
	_helpMenuText = nullptr;

	delete _nameText;
	_nameText = nullptr;
	delete _writeNameInstruction;
	_writeNameInstruction = nullptr;
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
    Texture* _writeNameInstruction;
};

#endif
