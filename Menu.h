#include <vector>

#include "Button.h"
#include "InputHandler.h"
#include "SystemModule.h"

#ifndef MENU_H
#define MENU_H

class Menu
{
public:
	Menu();
	~Menu();

	virtual void handleInput(InputHandler* input, SystemState& systemState) = 0;
	std::vector<Button*> getButtons();

protected:
	std::vector<Button*> _buttons;
	int _selectedButtonIndex;

private:

};

#endif
