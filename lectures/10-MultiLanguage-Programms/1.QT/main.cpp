#include <QApplication>
#include <QPushButton>
#include <QTranslator>
#include <QLocale>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTranslator translator;
    qDebug()<<QLocale();
    if(QLocale().system().language() == QLocale::Russian)
        translator.load("hellotr_la");
    else if (QLocale().system().language() == QLocale::English)
        translator.load("hellotr_en");
    app.installTranslator(&translator);
    QPushButton hello(QPushButton::tr("Hello world!"));
    hello.resize(100, 30);
    hello.show();
    return app.exec();
}