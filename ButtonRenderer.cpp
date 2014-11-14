#include "ButtonRenderer.h"

ButtonRenderer::~ButtonRenderer()
{


}

void ButtonRenderer::loadContent()
{
  //Load textures into texture vector
  _textTextures.push_back(_rm->loadTexture("PLAY", SDL_Color{255, 255, 255, 255}));
  _textTextures.push_back(_rm->loadTexture("HELP", SDL_Color{255, 255, 255, 255}));
  _textTextures.push_back(_rm->loadTexture("HIGHSCORE", SDL_Color{255, 255, 255, 255}));
  _textTextures.push_back(_rm->loadTexture("QUIT", SDL_Color{255, 255, 255, 255}));
  _textTextures.push_back(_rm->loadTexture("BACK", SDL_Color{ 255, 255, 255, 255 }));
}

void ButtonRenderer::render(Button* button, SDL_Renderer* renderer)
{
  if(button->getText() == "PLAY")
    _textTextures.at(0)->render(renderer, button->getX(), button->getY(), button->getWidth(), button->getHeight());
  else if(button->getText() == "HELP")
	  _textTextures.at(1)->render(renderer, button->getX(), button->getY(), button->getWidth(), button->getHeight());
  else if(button->getText() == "HIGHSCORE")
	  _textTextures.at(2)->render(renderer, button->getX(), button->getY(), button->getWidth(), button->getHeight());
  else if(button->getText() == "QUIT")
	  _textTextures.at(3)->render(renderer, button->getX(), button->getY(), button->getWidth(), button->getHeight());
  else if (button->getText() == "BACK")
	  _textTextures.at(4)->render(renderer, button->getX(), button->getY(), button->getWidth(), button->getHeight());
}
