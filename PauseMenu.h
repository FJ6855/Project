#include "Menu.h"

#ifndef PAUSEMENU_H
#define PAUSEMENU_H

class PauseMenu : public Menu
{
public:
	PauseMenu();
	~PauseMenu();

	void handleInput(InputHandler* input, SystemState& systemState) override;
private:
	void buildMenu();
};

#endif

