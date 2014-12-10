#include <string>

#include "Menu.h"
#include "InputHandler.h"
#include "HighScore.h"

#ifndef WRITENAMEMENU_H
#define WRITENAMEMENU_H

class WriteNameMenu : public Menu
{
public:
    WriteNameMenu(HighScore* hs)
    {
	_highscore = hs;
	buildMenu();
	_selectedButtonIndex = 0;
	_buttons.at(_selectedButtonIndex)->setButtonState(SELECTED);
	_name = "";
    }

    ~WriteNameMenu() = default;

    std::string getName();
    void handleInput(InputHandler* input, SystemState& systemState) override;

private:
    HighScore* _highscore;
    void buildMenu();
    std::string _name;
};

#endif
