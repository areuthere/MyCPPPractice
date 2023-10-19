#pragma once
#include <iostream>
#include <memory>
using namespace std;

namespace following
{
namespace patterns
{
#include <cmath>

enum class PointType
{
  cartesian,
  polar
};

class Point
{
  Point(float x, float y) : x(x), y(y){}
public:
  float x, y;

  friend class PointFactory;
};


//Factory class
class PointFactory
{
  static Point NewCartesian(float x, float y)
  {
    return Point{ x,y };
  }

  static Point NewPolar(float r, float theta)
  {
    return Point{ r*cos(theta), r*sin(theta) };
  }
};

} // namespace pattern

} // namespace following
