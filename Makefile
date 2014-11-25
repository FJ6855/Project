
CCC	= g++ -std=c++11
LFLAGS	= -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_image -lSDL2_ttf -lm

game: 	Main.o Game.o InputHandler.o MenuSystem.o StartMenu.o HelpMenu.o HighscoreMenu.o PauseMenu.o Menu.o SystemModule.o Level.o LevelSegment.o HighscoreMenuRenderer.o ButtonRenderer.o Button.o MenuRenderer.o Renderer.o ResourceManager.o Texture.o Object.o Block.o BlinkingBlock.o BlockRenderer.o Obstacle.o ObstacleRenderer.o Item.o ItemRenderer.o Player.o PlayerRenderer.o Background.o BackgroundRenderer.o Score.o HighScore.o WriteNameMenu.o
	$(CCC) -o game Main.o Game.o InputHandler.o MenuSystem.o StartMenu.o HelpMenu.o HighscoreMenu.o PauseMenu.o Menu.o SystemModule.o Level.o LevelSegment.o HighscoreMenuRenderer.o ButtonRenderer.o Button.o MenuRenderer.o Renderer.o ResourceManager.o Texture.o Object.o Block.o BlinkingBlock.o BlockRenderer.o Obstacle.o ObstacleRenderer.o Item.o ItemRenderer.o Player.o PlayerRenderer.o Background.o BackgroundRenderer.o HighScore.o Score.o WriteNameMenu.o $(LFLAGS)

Main.o : Main.cpp
	$(CCC) -c Main.cpp $(LFLAGS)

Game.o : Game.cpp Game.h
	$(CCC) -c Game.cpp $(LFLAGS)

InputHandler.o : InputHandler.cpp InputHandler.h
	$(CCC) -c InputHandler.cpp $(LFLAGS)

MenuSystem.o :  MenuSystem.cpp MenuSystem.h
	$(CCC) -c MenuSystem.cpp $(LFLAGS)

StartMenu.o :  StartMenu.cpp StartMenu.h
	$(CCC) -c StartMenu.cpp $(LFLAGS)

HelpMenu.o :  HelpMenu.cpp HelpMenu.h
	$(CCC) -c HelpMenu.cpp $(LFLAGS)

HighscoreMenu.o :  HighscoreMenu.cpp HighscoreMenu.h
	$(CCC) -c HighscoreMenu.cpp $(LFLAGS)

PauseMenu.o :  PauseMenu.cpp PauseMenu.h
	$(CCC) -c PauseMenu.cpp $(LFLAGS)

Menu.o :  Menu.cpp Menu.h
	$(CCC) -c Menu.cpp $(LFLAGS)

SystemModule.o :  SystemModule.cpp SystemModule.h
	$(CCC) -c SystemModule.cpp $(LFLAGS)

Level.o :  Level.cpp Level.h
	$(CCC) -c Level.cpp $(LFLAGS)

LevelSegment.o :  LevelSegment.cpp LevelSegment.h
	$(CCC) -c LevelSegment.cpp $(LFLAGS)

Player.o : Player.cpp Player.h
	$(CCC) -c Player.cpp $(LFLAGS)

HighscoreMenuRenderer.o :  HighscoreMenuRenderer.cpp HighscoreMenuRenderer.h
	$(CCC) -c HighscoreMenuRenderer.cpp $(LFLAGS)

ButtonRenderer.o :  ButtonRenderer.cpp ButtonRenderer.h
	$(CCC) -c ButtonRenderer.cpp $(LFLAGS)

Button.o : Button.cpp Button.h
	$(CCC) -c Button.cpp $(LFLAGS)

MenuRenderer.o :  MenuRenderer.cpp MenuRenderer.h
	$(CCC) -c MenuRenderer.cpp $(LFLAGS)

Renderer.o :  Renderer.cpp Renderer.h
	$(CCC) -c Renderer.cpp $(LFLAGS)

ResourceManager.o :  ResourceManager.cpp ResourceManager.h
	$(CCC) -c ResourceManager.cpp $(LFLAGS)

Texture.o : Texture.cpp Texture.h
	$(CCC) -c Texture.cpp $(LFLAGS)

Object.o : Object.cpp Object.h
	$(CCC) -c Object.cpp $(LFLAGS)

Block.o : Block.cpp Block.h
	$(CCC) -c Block.cpp $(LFLAGS)

BlinkingBlock.o : BlinkingBlock.cpp BlinkingBlock.h
	$(CCC) -c BlinkingBlock.cpp $(LFLAGS)

BlockRenderer.o : BlockRenderer.cpp BlockRenderer.h
	$(CCC) -c BlockRenderer.cpp $(LFLAGS)

Obstacle.o : Obstacle.cpp Obstacle.h
	$(CCC) -c Obstacle.cpp $(LFLAGS)

ObstacleRenderer.o : ObstacleRenderer.cpp ObstacleRenderer.h
	$(CCC) -c ObstacleRenderer.cpp $(LFLAGS)

Item.o : Item.cpp Item.h
	$(CCC) -c Item.cpp $(LFLAGS)

ItemRenderer.o : ItemRenderer.cpp ItemRenderer.h
	$(CCC) -c ItemRenderer.cpp $(LFLAGS)

PlayerRenderer.o : PlayerRenderer.cpp PlayerRenderer.h
	$(CCC) -c PlayerRenderer.cpp $(LFLAGS)

Background.o : Background.cpp Background.h
	$(CCC) -c Background.cpp $(LFLAGS)

BackgroundRenderer.o : BackgroundRenderer.cpp BackgroundRenderer.h
	$(CCC) -c BackgroundRenderer.cpp $(LFLAGS)

HighScore.o : HighScore.cpp HighScore.h
	$(CCC) -c HighScore.cpp $(LFLAGS)

Score.o : Score.cpp Score.h
	$(CCC) -c Score.cpp $(LFLAGS)

WriteNameMenu.o : WriteNameMenu.cpp WriteNameMenu.h
	$(CCC) -c WriteNameMenu.cpp $(LFLAGS)

clean:
	@ \rm -rf *.o *.gch core

zap: clean
	@ \rm -f game *~
