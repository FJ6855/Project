#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:    
    ~Object() = default;
  
    virtual Object* clone() const = 0;
    virtual void updateLogic() = 0;

    int getX();
    void setX(int);
    int getY();
    void setY(int);
    int getWidth();
    void setWidth(int);
    int getHeight();
    void setHeight(int);

protected:
    Object() : _width{0}, _height{0}, _x{0}, _y{0} {}
    Object(int x, int y, int width, int height) : _x{x}, _y{y}, _width{width}, _height{height} {}
    Object(const Object&) = default;
 
    int _width;
    int _height;
    int _x;
    int _y;
};

#endif
