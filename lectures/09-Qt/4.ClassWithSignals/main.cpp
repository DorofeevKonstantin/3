#include "mainwindow.h"

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QProgressBar>
#include <QObject>

#include <counter.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;
    w.setGeometry(0,0,800,600);
    w.setWindowTitle("Example from code");

    QPushButton b1(&w);
    b1.setGeometry(10,10,100,50);
    b1.setText("Maximize");

    QSlider sl1(&w);
    sl1.setGeometry(250,10,50,150);

    QProgressBar pb1(&w);
    pb1.setGeometry(50,100,200,50);

    QLabel label(&w);
    label.setGeometry(10,250,100,50);
    label.setText("123");

    Counter counter;

    //QObject::connect(&b1, SIGNAL(pressed()), &w, SLOT(showMaximized()));
    QObject::connect(&b1, &QPushButton::pressed, &w, &QMainWindow::showMaximized);
    QObject::connect(&sl1, &QSlider::valueChanged, &pb1, &QProgressBar::setValue);

    QObject::connect(&sl1, &QSlider::valueChanged, &counter, &Counter::setValue);
    QObject::connect(&counter, &Counter::valueChanged, &label, &QLabel::setText);

    w.show();
    return a.exec();
}
