#include "Menu.h"
#include "InputHandler.h"
#include "HighScore.h"
#include <string>

#ifndef WRITENAMEMENU_H
#define WRITENAMEMENU_H

class WriteNameMenu : public Menu
{
public:
  WriteNameMenu(HighScore* hs);
	~WriteNameMenu();

	std::string getName();
	void handleInput(InputHandler* input, SystemState& systemState) override;
private:
	HighScore* _highscore;
	void buildMenu();
	std::string _name;

};

#endif
