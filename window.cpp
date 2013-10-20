#include <iostream>
#include <QtGui>
#include <QtOpenGL>
#include "version.h"
#include "window.h"
//#include "dfuncs.h"

//------------------------------------------------------------------------------------
// Creates and initializes the main window for application
//------------------------------------------------------------------------------------
Window::Window(QWidget *parent):QDialog(parent)
{
	//Setup application interface. Creates all the required components and sliders.
	setupUi(this);
    resetMatrix();
    //We need to attach our m_glWidget to glWidgetArea
    //All our drawings will be on glWidgetArea
   //glWidgetArea->setWidget(&mGLWidget);
}

//void Window::resizeEvent( QResizeEvent * )
//{
//  cerr << "new size "<< width() SEP height() NL;
//  //m_glWidget->resizeGL(width(), height());
// // qttsnk->setGeometry(width()-320,  110, 100,  100);
//}


void Window::aboutBut()
{
    QString title="QtOpenGl-2 ";
    QString mess = "QtOpenGl-basic by Brian Wyvill Release Version: " + QString::number(MY_VERSION);
    QMessageBox::information( this, title, mess, QMessageBox::Ok );
}

//bool Window::checkData(QString tempStr, double *num)
//{
//    bool validate;
////no error message
//    *num = tempStr.toDouble(&validate);
//    if (validate == false) *num =0.0;
//    return validate;
//}

//void Window::txt0()
//{
//    double a;
//    if ( checkData(mat[0], &a) ) cerr << "data ok  ";
//    cerr << "a="<<a NL;
//}

//void Window::txt0(QString a)
//{
//    mat[0]=a;
//}

//void Window::txt9(QString a)
//{
//    mat[9]=a;
//    cerr << "Input string\n";
//}

//void Window::txt99()
//{
//    double a;
//    if ( checkData(mat[9], &a) ) cerr << "9data ok  ";
//    cerr << "a="<<a NL;
//     QMessageBox::information( this, "QtGl: ", mat[9], QMessageBox::Ok );
//}

//void Window::txt1()
//{
//    double a;
//    if ( checkData(mat[1], &a) ) cerr << "data ok  ";
//        cerr << "a="<<a NL;
//}

//void Window::txt1(QString a)
//{
//    mat[1]=a;
//}

void Window::pressmebut()
{
    std::cerr << "Don't press me!";
}

void Window::resetMatrix()
{
    inputMatrix[0][0] = 1;
    inputMatrix[0][1] = 0;
    inputMatrix[0][2] = 0;
    inputMatrix[0][3] = 0;
    inputMatrix[1][0] = 0;
    inputMatrix[1][1] = 1;
    inputMatrix[1][2] = 0;
    inputMatrix[1][3] = 0;
    inputMatrix[2][0] = 0;
    inputMatrix[2][1] = 0;
    inputMatrix[2][2] = 1;
    inputMatrix[2][3] = 0;
    inputMatrix[3][0] = 0;
    inputMatrix[3][1] = 0;
    inputMatrix[3][2] = 0;
    inputMatrix[3][3] = 1;
}

void Window::setMatrix(GLdouble value, int r, int c)
{
    inputMatrix[r][c] = value;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            std::cerr<< inputMatrix[i][j]<<" ";
        }
        std::cerr<<"\n";
    }
}

void Window::getInput00(QString s)
{
    setMatrix(s.toDouble(), 0, 0);
}

void Window::getInput01(QString s)
{
    setMatrix(s.toDouble(), 0, 1);
}

void Window::getInput02(QString s)
{
    setMatrix(s.toDouble(), 0, 3);
}

void Window::getInput10(QString s)
{
    setMatrix(s.toDouble(), 1, 0);
}

void Window::getInput11(QString s)
{
    setMatrix(s.toDouble(), 1, 1);
}

void Window::getInput12(QString s)
{
    setMatrix(s.toDouble(), 1, 3);
}

void Window::getInput20(QString s)
{
    setMatrix(s.toDouble(), 3, 0);
}

void Window::getInput21(QString s)
{
    setMatrix(s.toDouble(), 3, 1);
}

void Window::getInput22(QString s)
{
    setMatrix(s.toDouble(), 3, 3);
}
