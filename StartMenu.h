#include "Menu.h"

#ifndef STARTMENU_H
#define STARTMENU_H


class StartMenu : public Menu
{
public:
	StartMenu();
	~StartMenu();
	
	void handleInput(InputHandler* input, SystemState& systemState) override;
private:
	void buildMenu();
};

#endif

