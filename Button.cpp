#include "Button.h"

Button::Button(std::string text, int x, int y, int width, int height, SystemState systemState) : _text{ text }, _x{ x }, _y{ y }, _width{ width }, _height{ height }, _systemState{ systemState }
{

}

Button::~Button()
{

}

std::string Button::getText()
{
	return _text;
}

int Button::getX()
{
	return _x;
}

int Button::getY()
{
	return _y;
}

int Button::getWidth()
{
	return _width;
}

int Button::getHeight()
{
	return _height;
}

ButtonState Button::getButtonState()
{
  return _buttonState;
}

void Button::setButtonState(ButtonState buttonState)
{
  _buttonState = buttonState;
}

SystemState Button::getSystemState()
{
	return _systemState;
}
