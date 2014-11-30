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
	//Animation sprites
	Texture* _playerTextureRunningRight0;
	Texture* _playerTextureRunningRight1;
	Texture* _playerTextureRunningRight2;
	Texture* _playerTextureRunningRight3;
	Texture* _playerTextureRunningRight4;
	Texture* _playerTextureRunningRight5;

	Texture* _playerTextureRunningLeft0;
	Texture* _playerTextureRunningLeft1;
	Texture* _playerTextureRunningLeft2;
	Texture* _playerTextureRunningLeft3;
	Texture* _playerTextureRunningLeft4;
	Texture* _playerTextureRunningLeft5;

	//Player sprites in the air
	Texture* _playerTextureInAirRight;
	Texture* _playerTextureInAirLeft;

	//The texture that is rendered every time. Will be pointing to one of the textures above
	Texture* _playerTexture;

	//Textures for health bar
	Texture* _healthBarTexture;
	Texture* _healthBarTextTexture;

	//Textures for the score
	Texture* _scoreTexture = nullptr;
	Texture* _scoreTextTexture;

	Texture* _lastHighestScoreTexture = nullptr;
	Texture* _lastHighestScoreTextTexture;

	Texture* _lastScoreTexture = nullptr;
	Texture* _lastScoreTextTexture;
	
	int _playerFrame;
};

#endif
