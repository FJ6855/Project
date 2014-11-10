class Object
{
 public:

  Object() : _width{0}, _height{0}, _x{0}, _y{0} {}
  virtual Object(int width, int height, int x, int y) : _width{width}, _height{height}, _x{x}, _y{y} {}
  
  int getX();
  void setX(int);
  int getY();
  void setY(int);
  int getWidth();
  void setWidth(int);
  int getHeight();
  void setHeight(int);
  
  virtual void updateLogic() = 0;

 private:

  int _width;
  int _height;
  int _x; 
  int _y;
}
