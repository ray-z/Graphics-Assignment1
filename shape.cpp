#include "shape.h"
#include <iostream>
shape::shape(int XCentre, int YCentre, const QColor& colour, const QColor& selectedColour):
    mXCentre(XCentre),
    mYCentre(YCentre),
    mNormalColour(colour),
    mSelectedColour(selectedColour)
{
    //resetMatrix(mMatrix);
    resetMatrix(tempMatrix);

}

shape::~shape()
{}

void shape::draw(bool selected)
{
    //Ensure we're in the correct mode for drawing
    glMatrixMode(GL_MODELVIEW);

    //In order to translate only this shape, we need to push and pop the current matrix
    glPushMatrix();

    //Translate the shape so that its centre is in the right location
    glTranslated(mXCentre, mYCentre, 0.0);

    //Opengl Uses column-major matrix ordering
     glMultTransposeMatrixf(mMatrix.data());

    //Set the colour
    glColor3f(mNormalColour.redF(), mNormalColour.greenF(), mNormalColour.blueF());

    //Draw the actual shape
    glBegin(GL_POLYGON);
    drawShape();
    glEnd();

    //If it's selected, draw a highlight
    if(selected)
    {
    glColor3f(mSelectedColour.redF(), mSelectedColour.greenF(), mSelectedColour.blueF());

    const float lineWidth = 3.0;
    glLineWidth(lineWidth);

    glBegin(GL_LINE_LOOP);
    drawShape();
    glEnd();
    }

    //Restore the original matrix
    glPopMatrix();
}

void shape::setCentre(int X, int Y)
{
    mXCentre = X;
    mYCentre = Y;
}

void shape::translateBy(int X, int Y)
{
    mXCentre += X;
    mYCentre += Y;
}


bool shape::inside(int x, int y)
{
    //Translate the co-ordinates
    bool insideShape = insideZeroCentredShape(x-mXCentre, mYCentre-y);

    return insideShape;
}

void shape::resetMatrix(GLdouble m[4][4])
{
    m[0][0] = 1;
    m[0][1] = 0;
    m[0][2] = 0;
    m[0][3] = 0;
    m[1][0] = 0;
    m[1][1] = 1;
    m[1][2] = 0;
    m[1][3] = 0;
    m[2][0] = 0;
    m[2][1] = 0;
    m[2][2] = 1;
    m[2][3] = 0;
    m[3][0] = 0;
    m[3][1] = 0;
    m[3][2] = 0;
    m[3][3] = 1;
}

void shape::setTempMatrix(GLdouble value, int r, int c)
{
    tempMatrix[r][c] = value;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            std::cerr<< tempMatrix[i][j]<<" ";
        }
        std::cerr<<"\n";
    }
}

void shape::transform(QTransform mat)
{
    QMatrix4x4 mat4(mat);

    mMatrix *=mat4;

    translateBy(mMatrix.toTransform().m13(), mMatrix.toTransform().m23());
}

void shape::setColor(QColor c)
{
    mNormalColour = c;
}
