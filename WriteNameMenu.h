#include "Menu.h"
#include "InputHandler.h"

#ifndef WRITENAMEMENU_H
#define WRITENAMEMENU_H

class WriteNameMenu : public Menu
{
public:
        WriteNameMenu();
	~WriteNameMenu();

	void handleInput(InputHandler* input, SystemState& systemState) override;
private:
	void buildMenu();
};

#endif
