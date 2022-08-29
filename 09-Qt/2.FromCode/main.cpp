#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QProgressBar>
#include <QSlider>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;

    w.setGeometry(100,50,600,800);
    QPushButton b1(&w);
    b1.setText("Maximize");
    b1.setGeometry(10,10,100,50);

    QObject::connect(&b1, SIGNAL(clicked(bool)), &w, SLOT(showMaximized()));

    QLineEdit edit(&w);
    edit.setGeometry(10,100,100,80);

    QProgressBar bar(&w);
    bar.setGeometry(500,100,100,80);

    QObject::connect(&edit, SIGNAL(textChanged(QString)), &bar, SLOT(setValue(int)));

    QSlider s1(&w);
    s1.setGeometry(600,10,100,50);
    QObject::connect(&s1, SIGNAL(valueChanged(int)), &bar, SLOT(setValue(int)));

    w.show();
    return a.exec();
}
