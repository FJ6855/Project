#include "Menu.h"

#ifndef STARTMENU_H
#define STARTMENU_H

class StartMenu : public Menu
{
public:
    StartMenu()
    {	
	buildMenu();
    }

    ~StartMenu() = default;

    void handleInput(InputHandler* input, SystemState& systemState) override;

private:
    void buildMenu() override;
};

#endif

