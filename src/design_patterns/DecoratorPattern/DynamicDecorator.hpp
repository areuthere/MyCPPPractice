#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <sstream>
using namespace std;


//Drawback of this pattern is that Decorated object of circle
//cannot use its member function moveCenter as it is not part of Shape interface

namespace following
{
namespace patterns
{

class Shape
{
    public:
    virtual string draw() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape
{
    int radius, x, y;
    public:

    Circle(int radius, int x, int y):radius(radius),x(x),y(y){}
    void moveCenter(int len, int hei)
    {
        x = x+len;
        y = y+len;
    }
    virtual string draw() const override
    {
        ostringstream ss;
        ss << "Draw Circle at x=" << x << " y=" <<y;
        return ss.str();
    }
};

class Square : public Shape
{
    int side, x, y;
    public:
    Square(int side):side(side){}
    virtual string draw() const override
    {
        ostringstream ss;
        ss << "Draw Square with side " << side << " at x=" << x << " y=" << y;
        return ss.str();
    }
};

class ColorShape : public Shape
{
    Shape& shape;
    string color;
    public:
    ColorShape(string color,Shape& shape):shape(shape),color(color){}
    string draw() const
    {
        ostringstream ss;
        ss << shape.draw() << " with color " << color;
        return ss.str();
    }
};

class BorderShape : public Shape
{
    Shape& shape;
    int border_size;
    public:
    BorderShape(Shape& shape, int border_size):shape(shape),border_size(border_size){}
    string draw() const
    {
        ostringstream ss;
        ss << shape.draw() << " with border_size " << border_size;
        return ss.str();
    }
};

class TransparentShape : public Shape
{
    Shape& shape;
    int transparency;
    public:
    TransparentShape(Shape& shape, int transparency):shape(shape),transparency(transparency){}
    string draw() const
    {
        ostringstream ss;
        ss << shape.draw() << " with transparency " << transparency;
        return ss.str();
    }
};

} // namespace patterns

} // namespace following
