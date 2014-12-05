#include "Menu.h"
#include "InputHandler.h"
#include "HighScore.h"

#ifndef HIGHSCOREMENU_H
#define HIGHSCOREMENU_H

class HighscoreMenu : public Menu
{
public:
	HighscoreMenu(HighScore* hs);
	~HighscoreMenu();

	void handleInput(InputHandler* input, SystemState& systemState) override;
	std::vector<Score*> getScores();
private:
	void buildMenu();
	HighScore* _highscore;
};

#endif

