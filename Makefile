
CCC	= g++ -std=c++11
LFLAGS	= -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_image -lSDL2_ttf -lm

game: 	Main.o Game.o InputHandler.o MenuSystem.o StartMenu.o HelpMenu.o HighscoreMenu.o PauseMenu.o Menu.o SystemModule.o Level.o LevelSegment.o HighscoreMenuRenderer.o ButtonRenderer.o Button.o MenuRenderer.o Renderer.o ResourceManager.o Texture.o Object.o Block.o BlinkingBlock.o SpeedBlock.o MovingBlock.o BlockRenderer.o Obstacle.o ObstacleRenderer.o Item.o ItemRenderer.o Health.o PowerUp.o SpeedBoost.o DoubleJump.o Player.o PlayerRenderer.o Background.o BackgroundRenderer.o Score.o HighScore.o WriteNameMenu.o
	$(CCC) -o game Main.o Game.o InputHandler.o MenuSystem.o StartMenu.o HelpMenu.o HighscoreMenu.o PauseMenu.o Menu.o SystemModule.o Level.o LevelSegment.o HighscoreMenuRenderer.o ButtonRenderer.o Button.o MenuRenderer.o Renderer.o ResourceManager.o Texture.o Object.o Block.o BlinkingBlock.o SpeedBlock.o MovingBlock.o BlockRenderer.o Obstacle.o ObstacleRenderer.o Item.o ItemRenderer.o Health.o PowerUp.o SpeedBoost.o DoubleJump.o Player.o PlayerRenderer.o Background.o BackgroundRenderer.o HighScore.o Score.o WriteNameMenu.o $(LFLAGS)

Main.o : Main.cpp
	$(CCC) -c Main.cpp 

Game.o : Game.cpp Game.h
	$(CCC) -c Game.cpp 

InputHandler.o : InputHandler.cpp InputHandler.h
	$(CCC) -c InputHandler.cpp 

MenuSystem.o :  MenuSystem.cpp MenuSystem.h
	$(CCC) -c MenuSystem.cpp 

StartMenu.o :  StartMenu.cpp StartMenu.h
	$(CCC) -c StartMenu.cpp 

HelpMenu.o :  HelpMenu.cpp HelpMenu.h
	$(CCC) -c HelpMenu.cpp 

HighscoreMenu.o :  HighscoreMenu.cpp HighscoreMenu.h
	$(CCC) -c HighscoreMenu.cpp 

PauseMenu.o :  PauseMenu.cpp PauseMenu.h
	$(CCC) -c PauseMenu.cpp 

Menu.o :  Menu.cpp Menu.h
	$(CCC) -c Menu.cpp

SystemModule.o :  SystemModule.cpp SystemModule.h
	$(CCC) -c SystemModule.cpp 

Level.o :  Level.cpp Level.h
	$(CCC) -c Level.cpp 

LevelSegment.o :  LevelSegment.cpp LevelSegment.h
	$(CCC) -c LevelSegment.cpp 

Player.o : Player.cpp Player.h
	$(CCC) -c Player.cpp

HighscoreMenuRenderer.o :  HighscoreMenuRenderer.cpp HighscoreMenuRenderer.h
	$(CCC) -c HighscoreMenuRenderer.cpp

ButtonRenderer.o :  ButtonRenderer.cpp ButtonRenderer.h
	$(CCC) -c ButtonRenderer.cpp

Button.o : Button.cpp Button.h
	$(CCC) -c Button.cpp

MenuRenderer.o :  MenuRenderer.cpp MenuRenderer.h
	$(CCC) -c MenuRenderer.cpp

Renderer.o :  Renderer.cpp Renderer.h
	$(CCC) -c Renderer.cpp

ResourceManager.o :  ResourceManager.cpp ResourceManager.h
	$(CCC) -c ResourceManager.cpp

Texture.o : Texture.cpp Texture.h
	$(CCC) -c Texture.cpp

Object.o : Object.cpp Object.h
	$(CCC) -c Object.cpp

Block.o : Block.cpp Block.h
	$(CCC) -c Block.cpp

BlinkingBlock.o : BlinkingBlock.cpp BlinkingBlock.h
	$(CCC) -c BlinkingBlock.cpp 

SpeedBlock.o : SpeedBlock.cpp SpeedBlock.h
	$(CCC) -c SpeedBlock.cpp

MovingBlock.o : MovingBlock.cpp MovingBlock.h
	$(CCC) -c MovingBlock.cpp

BlockRenderer.o : BlockRenderer.cpp BlockRenderer.h
	$(CCC) -c BlockRenderer.cpp

Obstacle.o : Obstacle.cpp Obstacle.h
	$(CCC) -c Obstacle.cpp

ObstacleRenderer.o : ObstacleRenderer.cpp ObstacleRenderer.h
	$(CCC) -c ObstacleRenderer.cpp

Item.o : Item.cpp Item.h
	$(CCC) -c Item.cpp

ItemRenderer.o : ItemRenderer.cpp ItemRenderer.h
	$(CCC) -c ItemRenderer.cpp

Health.o : Health.cpp Health.h
	$(CCC) -c Health.cpp

PowerUp.o : PowerUp.cpp PowerUp.h
	$(CCC) -c PowerUp.cpp

SpeedBoost.o : SpeedBoost.cpp SpeedBoost.h
	$(CCC) -c SpeedBoost.cpp

DoubleJump.o : DoubleJump.cpp DoubleJump.h
	$(CCC) -c DoubleJump.cpp

PlayerRenderer.o : PlayerRenderer.cpp PlayerRenderer.h
	$(CCC) -c PlayerRenderer.cpp

Background.o : Background.cpp Background.h
	$(CCC) -c Background.cpp

BackgroundRenderer.o : BackgroundRenderer.cpp BackgroundRenderer.h
	$(CCC) -c BackgroundRenderer.cpp

HighScore.o : HighScore.cpp HighScore.h
	$(CCC) -c HighScore.cpp 

Score.o : Score.cpp Score.h
	$(CCC) -c Score.cpp

WriteNameMenu.o : WriteNameMenu.cpp WriteNameMenu.h
	$(CCC) -c WriteNameMenu.cpp

clean:
	@ \rm -rf *.o *.gch core

zap: clean
	@ \rm -f game *~
