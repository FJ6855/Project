#include "Menu.h"

#ifndef PAUSEMENU_H
#define PAUSEMENU_H

class PauseMenu : public Menu
{
public:
    PauseMenu()
    {
	buildMenu();
    }
    
    ~PauseMenu() = default;

    void handleInput(InputHandler* input, SystemState& systemState) override;

private:
    void buildMenu() override;
};

#endif
