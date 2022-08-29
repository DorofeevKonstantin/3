#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent* event) override;

private:
    Ui::MainWindow *ui;
    QPixmap* pixmap;
    QTimer* drawTimer;
    QPainter* qpainter;
    QPoint lastPoint, currentPoint;

public slots:
    void showImageSlot();
    void startAnimationSlot();
    void drawSlot();
};
#endif // MAINWINDOW_H
