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

	// Textures for power up timer
	Texture* _powerUpTimerTexture = nullptr;
	Texture* _powerUpTimerTextTexture;
	
	int _playerFrame;
};

#endif
