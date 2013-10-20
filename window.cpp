#include <iostream>
#include <QtGui>
#include <QtOpenGL>
#include "version.h"
#include "window.h"
#include "glwidget.h"
//#include "dfuncs.h"

//------------------------------------------------------------------------------------
// Creates and initializes the main window for application
//------------------------------------------------------------------------------------
Window::Window(QWidget *parent):QDialog(parent)
{
	//Setup application interface. Creates all the required components and sliders.
    ui = new Ui::frmMain;
    ui->setupUi(this);

    resetMatrix();
    //We need to attach our m_glWidget to glWidgetArea
    //All our drawings will be on glWidgetArea
   //glWidgetArea->setWidget(&mGLWidget);
}
Window::~Window()
{
    delete ui;
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

void Window::resetTxt()
{
    ui->lineEdit00->setText("1");
    ui->lineEdit01->setText("0");
    ui->lineEdit02->setText("0");
    ui->lineEdit10->setText("0");
    ui->lineEdit11->setText("1");
    ui->lineEdit12->setText("0");
    ui->lineEdit20->setText("0");
    ui->lineEdit21->setText("0");
    ui->lineEdit22->setText("1");
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

void Window::setMatrix(QString value, int r, int c)
{
    inputMatrix[r][c] = value.toDouble();
}

void Window::storeMatrix()
{
    setMatrix(ui->lineEdit00->text(), 0, 0);
    setMatrix(ui->lineEdit01->text(), 0, 1);
    setMatrix(ui->lineEdit02->text(), 0, 3);
    setMatrix(ui->lineEdit10->text(), 1, 0);
    setMatrix(ui->lineEdit11->text(), 1, 1);
    setMatrix(ui->lineEdit12->text(), 1, 3);
    setMatrix(ui->lineEdit20->text(), 3, 0);
    setMatrix(ui->lineEdit21->text(), 3, 1);
    setMatrix(ui->lineEdit22->text(), 3, 3);
    resetTxt();
}

void Window::sendToWidget()
{
    storeMatrix();
    ui->widget->sendToShape(inputMatrix);
}
