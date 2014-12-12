#include "Menu.h"
#include "InputHandler.h"

#ifndef HELPMENU_H
#define HELPMENU_H

class HelpMenu : public Menu
{
public:
    HelpMenu()
    {
	buildMenu();
    }

    ~HelpMenu() = default;

    void handleInput(InputHandler* input, SystemState& systemState, SystemState& lastSystemState) override;

private:
    void buildMenu() override;
};

#endif
