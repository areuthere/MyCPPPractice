#pragma once
#include <iostream>
using namespace std;

namespace following
{
namespace patterns
{
    class LegacyRectangle
    {
        int mX1,mX2,mY1,mY2;
        public:
        LegacyRectangle(int x1, int y1, int x2, int y2):mX1(x1),mX2(x2),mY1(y1),mY2(y2){}
        void olddraw()
        {
            cout << "using old method to draw using four coordinates " << endl;
        }
    };

// Client wants to change interface to provide width, height instead of x2,y2 coordinates.
    class NewRectangleInterface
    {
        public:
        virtual void draw() = 0;
        virtual ~NewRectangleInterface()=default;
    };

    class RectangleAdapter : public NewRectangleInterface, private LegacyRectangle
    {
        public:
        RectangleAdapter(int x, int y, int w, int h):LegacyRectangle(x,y,x+w,y+h){}
        void draw() override
        {
            olddraw();
        }
    };
} // namespace patterns

} // namespace following
