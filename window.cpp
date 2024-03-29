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

void Window::pressmebut()
{
    std::cerr << "Don't press me!";
}

void Window::resetTxt()
{
    ui->dsb00->setValue(1.0);
    ui->dsb01->setValue(0.0);
    ui->dsb02->setValue(0.0);
    ui->dsb10->setValue(0.0);
    ui->dsb11->setValue(1.0);
    ui->dsb12->setValue(0.0);
    ui->dsb20->setValue(0.0);
    ui->dsb21->setValue(0.0);
    ui->dsb22->setValue(1.0);
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

void Window::setTxt(QTransform qt)
{
    ui->dsb00->setValue(qt.m11());
    ui->dsb01->setValue(qt.m12());
    ui->dsb02->setValue(qt.m13());
    ui->dsb10->setValue(qt.m21());
    ui->dsb11->setValue(qt.m22());
    ui->dsb12->setValue(qt.m23());
    ui->dsb20->setValue(qt.m31());
    ui->dsb21->setValue(qt.m32());
    ui->dsb22->setValue(qt.m33());
}

void Window::getInput()
{
    inputMat.setMatrix(ui->dsb00->value(), ui->dsb01->value(), ui->dsb02->value(),
                       ui->dsb10->value(), ui->dsb11->value(), ui->dsb12->value(),
                       ui->dsb20->value(), ui->dsb21->value(), ui->dsb22->value());
}


void Window::storeMatrix()
{
    getInput();
    savedMatrices.push_back(inputMat);

}

void Window::sendToWidget()
{
    //storeMatrix();
    getInput();

    ui->widget->sendToShape(inputMat);
}

void Window::showMatrix(int num)
{
    resetTxt();
    QStack<QTransform> tempQStack = savedMatrices;


    if(num > 0 && num < savedMatrices.size()+1)
    {
        for(int i=1; i<num; i++)
        {
            tempQStack.pop_back();
        }
        setTxt(tempQStack.top());
    }

}

void Window::addToMult()
{
    getInput();
    multMatrices.push_front(inputMat);
    ui->transList->insert("[" + ui->matrixNum->text() + "]");
}

void Window::clearList()
{
    multMatrices.clear();
    ui->transList->setText("");
}

void Window::sendMultToWidget()
{
    QStack<QTransform> tempQStack = multMatrices;
    while(tempQStack.size() != 0)
    {
        ui->widget->sendToShape(tempQStack.pop());
    }
}

void Window::sendColor()
{
    QColor c;
    switch(ui->colorBox->currentIndex())
    {
        case 0:
            c.setRedF(1);
            break;
        case 1:
            c.setGreenF(1);
            break;
        case 2:
            c.setBlueF(1);
            break;
    }
    ui->widget->changeColor(c);
}
