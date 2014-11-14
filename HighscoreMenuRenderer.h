#include "MenuRenderer.h"
#ifndef HIGHSCOREMENURENDERER_H
#define HIGHSCOREMENURENDERER_H

class HighscoreMenuRenderer : public MenuRenderer
{
public:
	HighscoreMenuRenderer(ResourceManager* rm) : MenuRenderer{ rm } {}
	~HighscoreMenuRenderer();


};

#endif
