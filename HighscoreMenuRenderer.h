#include <vector>

#include "MenuRenderer.h"
#include "HighScore.h"
#include "HighscoreMenu.h"
#include "Texture.h"

#ifndef HIGHSCOREMENURENDERER_H
#define HIGHSCOREMENURENDERER_H

class HighscoreMenuRenderer : public MenuRenderer
{
public:
    HighscoreMenuRenderer(ResourceManager* rm) : MenuRenderer(rm)
    {
	loadContent();
    }

    ~HighscoreMenuRenderer()
    {
	for (Texture* t : _scoreTextures)
	{
	    delete t;
	    t = nullptr;
	}

	delete _highscoreMenuText;
	_highscoreMenuText = nullptr;
	delete _menuBackground;
	_menuBackground = nullptr;
    }

    void loadContent() override;
    void render(HighscoreMenu* menu, SDL_Renderer* renderer);

private:
    std::vector<Texture*> _scoreTextures;

    Texture* _highscoreMenuText;
    Texture* _menuBackground;
};

#endif
