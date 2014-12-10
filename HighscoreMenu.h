#include "Menu.h"
#include "InputHandler.h"
#include "HighScore.h"

#ifndef HIGHSCOREMENU_H
#define HIGHSCOREMENU_H

class HighscoreMenu : public Menu
{
public:
    HighscoreMenu(HighScore* hs) : _highscore{hs} 
    {	
	buildMenu();
	_selectedButtonIndex = 0;
	_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
    }

    ~HighscoreMenu() = default;

    void handleInput(InputHandler* input, SystemState& systemState) override;

    std::vector<Score*> getScores();

private:
    void buildMenu();
    HighScore* _highscore;
};

#endif

