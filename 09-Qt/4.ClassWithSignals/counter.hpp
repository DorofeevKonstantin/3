#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <QObject>
#include <QString>

class Counter: public QObject
{
    Q_OBJECT

private:
    int count;
signals:
    void valueChanged(QString);
public:
    Counter();
public slots:
    void setValue(int);
};

#endif // COUNTER_HPP
