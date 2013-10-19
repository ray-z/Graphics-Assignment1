#include "shape.h"
#include <iostream>
shape::shape(int XCentre, int YCentre, const QColor& colour, const QColor& selectedColour):
    mXCentre(XCentre),
    mYCentre(YCentre),
    mNormalColour(colour),
    mSelectedColour(selectedColour)
{
    /*
    mMatrix[0][0] = 1;
    mMatrix[0][1] = 0;
    mMatrix[0][2] = 0;
    mMatrix[0][3] = 0;
    mMatrix[1][0] = 0;
    mMatrix[1][1] = 1;
    mMatrix[1][2] = 0;
    mMatrix[1][3] = 0;
    mMatrix[2][0] = 0;
    mMatrix[2][1] = 0;
    mMatrix[2][2] = 1;
    mMatrix[2][3] = 0;
    mMatrix[3][0] = 0;
    mMatrix[3][1] = 0;
    mMatrix[3][2] = 0;
    mMatrix[3][3] = 1;
    */

    resetMatrix(mMatrix);
    resetMatrix(tempMatrix);

    //test
    testMatrix[0] = 1;
    testMatrix[1] = 0;
    testMatrix[2] = 0;
    testMatrix[3] = 0;
    testMatrix[4] = 0;
    testMatrix[5] = 1;
    testMatrix[6] = 0;
    testMatrix[7] = 0;
    testMatrix[8] = 0;
    testMatrix[9] = 0;
    testMatrix[10] = 1;
    testMatrix[11] = 0;
    testMatrix[12] = 0;
    testMatrix[13] = 0;
    testMatrix[14] = 0;
    testMatrix[15] = 1;

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

    //This might be a good place to add other transformations
    //(Here's an example, the identity matrix)
    /*
    GLdouble matrix[4][4];
    matrix[0][0] = 1;
    matrix[0][1] = 0;
    matrix[0][2] = 0;
    matrix[0][3] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = 1;
    matrix[1][2] = 0;
    matrix[1][3] = 0;
    matrix[2][0] = 0;
    matrix[2][1] = 0;
    matrix[2][2] = 1;
    matrix[2][3] = 0;
    matrix[3][0] = 0;
    matrix[3][1] = 0;
    matrix[3][2] = 0;
    matrix[3][3] = 1;
    glMultMatrixd(&matrix[0][0]);
    */
    //glGetDoublev(GL_MODELVIEW_MATRIX, testMatrix);
    //glMultMatrixd(&mMatrix[0][0]);
    //Opengl Uses column-major matrix ordering
    glMultTransposeMatrixd(&mMatrix[0][0]);

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

void shape::calTransformMatrix()
{
    GLdouble newMatrix[4][4];

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            newMatrix[i][j] = 0;
            for(int k=0; k<4; k++)
            {
                newMatrix[i][j] += mMatrix[i][k] * tempMatrix[k][j];
            }
        }
    }
    memcpy(mMatrix, newMatrix, sizeof(mMatrix));
}

void shape::testTransformation()
{

    mMatrix[0][3] = 30;
    mMatrix[1][3] = 30;
    //mMatrix[0][0] = 0.1;
    //mMatrix[1][1] = 0.1;
    //testMatrix[3] = 0.5;
    //testMatrix[7] = 0.5;
    //glMultMatrixd(testMatrix);

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            std::cerr<< mMatrix[i][j]<<" ";
        }
        std::cerr<<"\n";
    }

}
