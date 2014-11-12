
CCC	= g++ -std=c++11
LFLAGS	= -L/usr/lib/x86_64-linux-gnu -lSDL -lm

game: Main.cc Game.o Level.o
	$(CCC) -o game Game.cc InputHandler.cc ResourceManager.cc HighScore.cc Level.o $(LFLAGS)

Level.o: Level.cc LevelSegment.cc
	$(CCC) -c Level.cc LevelSegment.cc

clean:
	@ \rm -rf *.o *.gch core

zap: clean
	@ \rm -f simulation *~
