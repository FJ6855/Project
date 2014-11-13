
CCC	= g++ -std=c++11
LFLAGS	= -L/usr/lib/x86_64-linux-gnu -lSDL -lm

game: Main.cc InputHandler.cc ResourceManager.cc HighScore.cc Game.o Level.o
	$(CCC) -o game Main.cc InputHandler.cc ResourceManager.cc HighScore.cc Game.o Level.o $(LFLAGS)

Game.o: Game.cc
	$(CCC) -c Game.cc

Level.o: Level.cc LevelSegment.cc  
	$(CCC) -c Level.cc LevelSegment.cc

Object.o: Object.cc Block.cc Obstacle.cc Item.cc
	$(CCC) -c Object.cc Block.cc Obstacle.cc Item.cc

clean:
	@ \rm -rf *.o *.gch core

zap: clean
	@ \rm -f game *~
