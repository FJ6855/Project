#include "Menu.h"
#include "InputHandler.h"

#ifndef HELPMENU_H
#define HELPMENU_H

class HelpMenu : public Menu
{
public:
	HelpMenu();
	~HelpMenu();

	void handleInput(InputHandler* input, SystemState& systemState) override;
private:
	void buildMenu();
};

#endif
