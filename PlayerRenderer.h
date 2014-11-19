#include "Renderer.h"
#include "ResourceManager.h"
#include "Player.h"

#ifndef PLAYERRENDERER_H
#define PLAYERRENDERER_H

class PlayerRenderer : public Renderer
{
 public:
 PlayerRenderer(ResourceManager* rm) : Renderer{rm}
  {
	 loadContent();
  }
  ~PlayerRenderer();

  void loadContent() override;
  void render(Player* player, SDL_Renderer* renderer);
 private:
  Texture* _playerTexture;

};

#endif
