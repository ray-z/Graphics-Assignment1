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
    ~Window();
private:
    //GLWidget instance---by storing an instance, the widget is automatically created
    //and cleared up when the Window class is instantiated (i.e. no need for new/delete)
    GLWidget mGLWidget;

    Ui::frmMain *ui;
    //Store input matrix
    GLdouble inputMatrix[4][4];

public slots:
    //Store input matrix
    void storeMatrix();
    void sendToWidget();

private slots:
    void aboutBut();
    void pressmebut();
    //Reset QLineEdit
    void resetTxt();
    //Reset matrix
    void resetMatrix();
    //Set matrix value
    void setMatrix(QString value, int r, int c);

protected:
    // void  resizeEvent(QResizeEvent * );
};


#endif
