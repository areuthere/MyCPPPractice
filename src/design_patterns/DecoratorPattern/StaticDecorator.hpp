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

    Circle(int radius=0, int x=0, int y=0):radius(radius),x(x),y(y){}
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
    Square(int side=0):side(side){}
    virtual string draw() const override
    {
        ostringstream ss;
        ss << "Draw Square with side " << side << " at x=" << x << " y=" << y;
        return ss.str();
    }
};

template<typename T>
class ColorShape : public T
{
    string color;
    public:
    template<typename ... Args>
    ColorShape(string color, Args&& ... args):color(color),T(forward<Args>(args) ...)
    {
        static_assert(is_base_of<Shape, T>::value,"Template argument must be a Shape");
    }
    string draw() const
    {
        ostringstream ss;
        ss << T::draw() << " with color " << color;
        return ss.str();
    }
};

template<typename T>
class BorderShape : public T
{
    int border_size;
    public:
    template<typename ... Args>
    BorderShape(int border_size, Args&& ... args):border_size(border_size),T(forward<Args>(args) ...)
    {
        static_assert(is_base_of<Shape, T>::value,"Template argument must be a Shape");
    }
    string draw() const
    {
        ostringstream ss;
        ss << T::draw() << " with border_size " << border_size;
        return ss.str();
    }
};

template<typename T>
class TransparentShape : public T
{
    int transparency;
    public:
    template<typename ... Args>
    TransparentShape(int transparency, Args&& ... args):transparency(transparency),T(forward<Args>(args) ...)
    {
        static_assert(is_base_of<Shape, T>::value,"Template argument must be a Shape");
    }
    string draw() const
    {
        ostringstream ss;
        ss << T::draw() << " with transparency " << transparency;
        return ss.str();
    }
};

} // namespace patterns

} // namespace following
