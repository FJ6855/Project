#include "Button.h"

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

void Button::setSystemState(SystemState systemState)
{
    _systemState = systemState;
}
