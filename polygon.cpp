#include "polygon.h"

polygon::polygon(int XCentre, int YCentre, const QColor& colour,
                 const QColor& selectedColour, unsigned int radius, unsigned int sides) :
    shape(XCentre, YCentre, colour, selectedColour),
    mRadius(radius),
    mSides(sides)
{
}

void polygon::drawShape()
{
    for(int i = 0; i < mSides; i++)
    {
        glVertex2f(mRadius*cos(i*2*M_PI/mSides),
                   mRadius*sin(i*2*M_PI/mSides));
    }
    glLineWidth(2);
    glColor3f(0, 1, 0);
}

bool polygon::insideZeroCentredShape(int x, int y)
{
    float distFromCentre = qSqrt(x*x+y*y);

    return (distFromCentre <= mRadius);
}
