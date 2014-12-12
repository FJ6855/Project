#include <string>

#include "Menu.h"
#include "InputHandler.h"
#include "HighScore.h"

#ifndef WRITENAMEMENU_H
#define WRITENAMEMENU_H

class WriteNameMenu : public Menu
{
public:
    WriteNameMenu(HighScore* hs) : _highscore{hs}, _name{""}
    {
	buildMenu();
    }

    ~WriteNameMenu() = default;

    std::string getName();
    void handleInput(InputHandler* input, SystemState& systemState, SystemState& lastSystemState) override;

private:
    HighScore* _highscore;
    std::string _name;

    void buildMenu() override;
};

#endif
