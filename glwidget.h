//These two lines are header guiardians against multiple includes
#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QSharedPointer>
#include <list>

#include "shape.h"

//A shared pointer is a kind of smart pointer. It will call delete on our behalf
//when the shape is finished with
typedef QSharedPointer<shape> shape_ptr;

//This is our OpenGL Component we built it on top of QGLWidget
class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    //Constructor for GLWidget
    GLWidget(QWidget *parent = 0);

protected:
    //This is called before the first call to paintGL() or resizeGL()
    virtual void initializeGL();

    //This is called whenever the widget needs to be painted, e.g. by a call to the
    //parent method updateGL();, to render the scene
    virtual void paintGL();

    //This is called whenever the widget is resized
    virtual void resizeGL(int width, int height);

    //Handle mouse press event in scrollArea
    void mousePressEvent(QMouseEvent* event);

    void mouseReleaseEvent(QMouseEvent* event);
    //Handle Mouse Move Event

    void mouseMoveEvent(QMouseEvent* event);
    //  void wheelEvent(QWheelEvent *event);  // for zoom

private:
    std::list<shape_ptr> mShapes;

    shape_ptr mSelectedShape;
    //Store the location the user clicked
    int mClickLocationX;
    int mClickLocationY;

    QColor mShapeColour;
    QColor mHighlightColour;

    static const double ZMin;
    static const double ZMax;

    //Store polygon sides
    int pSides;

public slots:
    void clear();
    void newCircle();
    void newSquare();
    //Draw ne polygon
    void newPolygon();
    //Store sides of polygon
    void storeSides(int i);
    //Transform using matrix
    void transformShape();
    //Store input matrix
    void getInput00(QString);
    void getInput01(QString);
    void getInput02(QString);
    void getInput10(QString);
    void getInput11(QString);
    void getInput12(QString);
    void getInput20(QString);
    void getInput21(QString);
    void getInput22(QString);
};


#endif
