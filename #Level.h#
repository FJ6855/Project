#include <vector>

class Level
{
 public:
 Level(InputHandler* input, ResourceManager* rm) : _inputHandler{inputHandler}, _rm{rm} 
  {
    _player = new Player();
    _playerRenderer = new PlayerRenderer();

    loadLevel();
  }
 
  void handleInput();
  void updateLogic();
  void render();

  Player* getPlayer() { return _player; }

 private:
  InputHandler* _inputHandler;
  ResourceManager* _rm;
  
  vector<LevelSegment> _segments;
  vector<LevelSegment> _loadedSegments;

  int activeSegmentIndex;
  int currentDifficulty;
  
  Player* _player;
  PlayerRenderer* _playerRenderer;

  void handleCollisions();
  void loadLevel();
  void loadSegements();
};
