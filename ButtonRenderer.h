#include <vector>

#include "Renderer.h"
#include "ResourceManager.h"
#include "Button.h"

#ifndef BUTTONRENDERER_H
#define BUTTONRENDERER_H

class ButtonRenderer : public Renderer
{
public:
   ButtonRenderer(ResourceManager* rm) : Renderer{rm} {}
   
    ~ButtonRenderer()
    {
	for (Texture* t : _textTextures)
	    delete t;

	delete _buttonTextureDeselected;
	delete _buttonTextureSelected;
    }
  
    void loadContent() override;
    void render(Button* button, SDL_Renderer* renderer);

private:
    std::vector<Texture*> _textTextures;
    Texture* _buttonTextureDeselected;
    Texture* _buttonTextureSelected;
};

#endif
