#pragma once
#include <iostream>
using namespace std;

namespace following
{
namespace principles
{
class Rectangle
{
protected:
    int width, height;

public:
    Rectangle(const int width, const int height) : width{width}, height{height}
    {
    }

    int get_width() const
    {
        return width;
    }
    void set_width(const int width)
    {
        this->width = width;
    }
    int get_height() const
    {
        return height;
    }
    void set_height(const int height)
    {
        this->height = height;
    }

    int area() const
    {
        return width * height;
    }
};
struct RectangleFactory
{
    static Rectangle create_rectangle(int w, int h)
    {
        return Rectangle(w, h);
    }
    static Rectangle create_square(int size)
    {
        return Rectangle(size, size);
    }
};

void process(Rectangle& r)
{
  int w = r.get_width();
  r.set_height(10);

  std::cout << "expected area = " << (w * 10)
    << ", got " << r.area() << std::endl;
}

} // namespace principles

} // namespace following
