#include "Object.cc";

enum blockType{type1};

Block : public Object
{
 public:
 Block(int width, int height, int x, int y, blockType type) : _type{type}, Object(width, height, x, y){}

 blockType getType();
 void updateLogic();

 private:
  blockType _type;
}
