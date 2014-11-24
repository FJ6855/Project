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
	 _playerFrame = 0;
  }
  ~PlayerRenderer();

  void loadContent() override;
  void render(Player* player, SDL_Renderer* renderer);

 private:
	Texture* _playerTextureRunningRight1;
	Texture* _playerTextureRunningRight2;
	Texture* _playerTextureRunningRight3;

	Texture* _playerTextureRunningLeft1;
	Texture* _playerTextureRunningLeft2;
	Texture* _playerTextureRunningLeft3;

	Texture* _playerTextureInAirRight;
	Texture* _playerTextureInAirLeft;

	Texture* _playerTexture;

	Texture* _healthBarTexture;
	Texture* _healthBarTextTexture;

	Texture* _scoreTexture = nullptr;
	Texture* _scoreTextTexture;

	Texture* _lastScoreTexture = nullptr;
	Texture* _lastScoreTextTexture;
	
	int _playerFrame;
};

#endif
