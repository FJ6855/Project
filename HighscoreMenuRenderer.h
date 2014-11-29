#include "MenuRenderer.h"
#include "HighScore.h"
#include "HighscoreMenu.h"
#include "Texture.h"
#include <vector>

#ifndef HIGHSCOREMENURENDERER_H
#define HIGHSCOREMENURENDERER_H

class HighscoreMenuRenderer : public MenuRenderer
{
 public:
	HighscoreMenuRenderer(ResourceManager* rm) : MenuRenderer{ rm }
    {
	  for(int i{} ; i < 10; ++i)
	  {
	      _scoreTextures.push_back(nullptr);
	  }
		_highscoreMenuText = rm->loadTexture("highscoreMenuText");
		_menuBackground = rm->loadTexture("menuBackground");
      }

	~HighscoreMenuRenderer();


	void render(HighscoreMenu* menu, SDL_Renderer* renderer);

 private:
	std::vector<Texture*> _scoreTextures;

	Texture* _highscoreMenuText;
	Texture* _menuBackground;
};

#endif
