#include "ButtonRenderer.h"

ButtonRenderer::~ButtonRenderer()
{


}

void ButtonRenderer::loadContent()
{
	_buttonTextureSelected = _rm->loadTexture("buttonTextureSelected");
	_buttonTextureDeselected = _rm->loadTexture("buttonTextureDeselected");

	//Load textures into texture vector
	_textTextures.push_back(_rm->loadTexture("PLAY", SDL_Color{255, 255, 255, 255}));
	_textTextures.push_back(_rm->loadTexture("HELP", SDL_Color{255, 255, 255, 255}));
	_textTextures.push_back(_rm->loadTexture("HIGHSCORE", SDL_Color{255, 255, 255, 255}));
	_textTextures.push_back(_rm->loadTexture("QUIT", SDL_Color{255, 255, 255, 255}));
	_textTextures.push_back(_rm->loadTexture("BACK", SDL_Color{ 255, 255, 255, 255 }));
	_textTextures.push_back(_rm->loadTexture("RESUME", SDL_Color{ 255, 255, 255, 255 }));
	_textTextures.push_back(_rm->loadTexture("ACCEPT", SDL_Color{ 255, 255, 255, 255 }));
	_textTextures.push_back(_rm->loadTexture("CANCEL", SDL_Color{ 255, 255, 255, 255 }));
}

void ButtonRenderer::render(Button* button, SDL_Renderer* renderer)
{ 
	if (button->getButtonState() == SELECTED) _buttonTextureSelected->render(renderer, button->getX() - 150 / 2, button->getY(), 150, 50);
	if (button->getButtonState() == NOTSELECTED) _buttonTextureDeselected->render(renderer, button->getX() - 150 / 2, button->getY(), 150, 50);

	if(button->getText() == "PLAY")
		_textTextures.at(0)->render(renderer, button->getX() - 30, button->getY() + 10, button->getWidth(), button->getHeight());
	else if(button->getText() == "HELP")
		_textTextures.at(1)->render(renderer, button->getX() - 30, button->getY() + 10, button->getWidth(), button->getHeight());
	else if(button->getText() == "HIGHSCORE")
		_textTextures.at(2)->render(renderer, button->getX() - 64, button->getY() + 10, button->getWidth() + 68, button->getHeight());
	else if(button->getText() == "QUIT")
		_textTextures.at(3)->render(renderer, button->getX() - 30, button->getY() + 10, button->getWidth(), button->getHeight());
	else if (button->getText() == "BACK")
		_textTextures.at(4)->render(renderer, button->getX() - 30, button->getY() + 10, button->getWidth(), button->getHeight());
	else if (button->getText() == "RESUME")
		_textTextures.at(5)->render(renderer, button->getX() - 48, button->getY() + 10, button->getWidth() + 35, button->getHeight());
	else if (button->getText() == "ACCEPT")
		_textTextures.at(6)->render(renderer, button->getX() - 48, button->getY() + 10, button->getWidth() + 35, button->getHeight());
	else if (button->getText() == "CANCEL")
		_textTextures.at(7)->render(renderer, button->getX() - 48, button->getY() + 10, button->getWidth() + 35, button->getHeight());
}
