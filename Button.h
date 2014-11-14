#include <string>

#include "SystemModule.h"

#ifndef BUTTON_H
#define BUTTON_H

enum ButtonState
{
	SELECTED,
	NOTSELECTED
};

class Button
{
public:
	Button(std::string text, int x, int y, int width, int height, SystemState systemState);
	~Button();

	std::string getText();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	ButtonState getButtonState();
	void setButtonState(ButtonState buttonState);
	SystemState getSystemState();
	
private:
	std::string _text;
	int _x;
	int _y;
	int _width;
	int _height;
	SystemState _systemState;
	ButtonState _buttonState;
};

#endif

