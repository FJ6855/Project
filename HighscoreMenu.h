#include "Menu.h"
#include "InputHandler.h"

#ifndef HIGHSCOREMENU_H
#define HIGHSCOREMENU_H

class HighscoreMenu : public Menu
{
public:
	HighscoreMenu();
	~HighscoreMenu();

	void handleInput(InputHandler* input, SystemState& systemState) override;
private:
	void buildMenu();
};

#endif

