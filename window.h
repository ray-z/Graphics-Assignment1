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
    //Store Matrices
    QStack<QTransform> savedMatrices;
    //input matrix
    QTransform inputMat;
    //Store Mult Matrices
    QStack<QTransform> multMatrices;


public slots:
    //Store input matrix
    void storeMatrix();
    void sendToWidget();
    //Add Matrix to Mult List
    void addToMult();
    //Clear Mult List
    void clearList();
    //Send a list of matrix
    void sendMultToWidget();

private slots:
    void aboutBut();
    void pressmebut();
    //Reset QLineEdit
    void resetTxt();
    //Reset matrix
    void resetMatrix();
    //Set matrix value
    void setTxt(QTransform);
    //Show selected matrix
    void showMatrix(int num);
    //GEt input matrix
    void getInput();


protected:
    // void  resizeEvent(QResizeEvent * );
};


#endif
