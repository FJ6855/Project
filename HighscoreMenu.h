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
    }

    ~HighscoreMenu() = default;

    void handleInput(InputHandler* input, SystemState& systemState);

    std::vector<Score*> getScores();

private:
    HighScore* _highscore;

    void buildMenu() override;
};

#endif

