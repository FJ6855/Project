#include <sstream>
#include <iomanip>

#include "HighscoreMenuRenderer.h"

void HighscoreMenuRenderer::render(HighscoreMenu* menu, SDL_Renderer* renderer)
{
    _menuBackground->render(renderer, 0, 0, 896, 512);

    _highscoreMenuText->render(renderer, 896 / 2 - _highscoreMenuText->getWidth()/2, 0, _highscoreMenuText->getWidth(), _highscoreMenuText->getHeight());

    std::vector<Score*> _scores = menu->getScores();

    for(int i{} ; i < _scores.size(); ++i)
    {
	std::stringstream ss;
	std::string line;

	ss << i+1 << ". " << std::left << std::setfill('.') << std::setw(20) << _scores.at(i)->getName() << _scores.at(i)->getScore();

	getline(ss,line);

	delete _scoreTextures.at(i);

	_scoreTextures.at(i) = _rm->loadTexture(line, SDL_Color{255, 255, 255});
	_scoreTextures.at(i)->render(renderer, 896/3 + 40, 100 + i*25, _scoreTextures.at(i)->getWidth(), _scoreTextures.at(i)->getHeight());
    }

    std::vector<Button*> v = menu->getButtons();

    for (int i = 0; i < v.size(); ++i)
	_buttonRenderer->render(v.at(i), renderer);
}
