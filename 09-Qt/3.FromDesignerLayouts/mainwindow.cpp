#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QObject>
#include <QTimer>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QPoint>
#include <QRandomGenerator>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawTimer = new QTimer();
    drawTimer->setInterval(100);
    QObject::connect(drawTimer, &QTimer::timeout, this, &MainWindow::drawSlot);

    ui->buttonsLayout->setAlignment(Qt::AlignTop);

    QObject::connect(ui->drawButton, SIGNAL(clicked()), this, SLOT(startAnimationSlot()));
    QObject::connect(ui->exitButton, &QPushButton::clicked, this, &QMainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "clicked on window";
}

void MainWindow::showImageSlot()
{
    *pixmap = pixmap->scaled(ui->mainLabel->size());
    ui->mainLabel->setPixmap(*pixmap);
}

void MainWindow::startAnimationSlot()
{
    if(ui->drawButton->text() == "Draw")
    {
        ui->drawButton->setText("Stop");
        pixmap = new QPixmap(ui->mainLabel->width(),ui->mainLabel->height());
        pixmap->fill(Qt::gray);
        ui->mainLabel->setPixmap(*pixmap);
        qpainter = new QPainter(pixmap);
        qpainter->setPen(QPen(Qt::red,3));
        lastPoint = {0,0};

        drawTimer->start();
    }
    else
    {
        //QObject::disconnect(drawTimer, &QTimer::timeout, this, &MainWindow::drawSlot);
        ui->drawButton->setText("Draw");
        drawTimer->stop();
        delete qpainter;
        delete pixmap;
        ui->mainLabel->clear();
    }
}

void MainWindow::drawSlot()
{
    currentPoint.setX(QRandomGenerator::global()->generate()%(ui->mainLabel->width() -1));
    currentPoint.setY(QRandomGenerator::global()->generate()%(ui->mainLabel->height() -1));
    qpainter->drawLine(lastPoint, currentPoint);
    ui->mainLabel->setPixmap(*pixmap);
    lastPoint = currentPoint;
}
