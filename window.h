//-------------------------------------------------------------------------------------------
//  University of Bath Computer Science Department
//	FrameWork for OpenGL application under QT
//  Course title: Introduction Computer Graphics
//-------------------------------------------------------------------------------------------
#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <QColorDialog>
#include "ui_MainWindow.h"
#include "glwidget.h"

class GLWidget;

//Create a window and load the components from generated code ui_MainWindow.h
class Window : public QDialog, public Ui::frmMain
{
    Q_OBJECT;

public:
    //Constructor
    Window(QWidget *parent = 0);

private:
    //GLWidget instance---by storing an instance, the widget is automatically created
    //and cleared up when the Window class is instantiated (i.e. no need for new/delete)
    GLWidget mGLWidget;

    //Store input matrix
    GLdouble inputMatrix[4][4];

public slots:
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

private slots:
    void aboutBut();
    void pressmebut();
    //Reset matrix
    void resetMatrix();
    //Set matrix value
    void setMatrix(GLdouble value, int r, int c);

protected:
    // void  resizeEvent(QResizeEvent * );
};


#endif
