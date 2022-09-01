#include "counter.hpp"

Counter::Counter()
{

}

void Counter::setValue(int newValue)
{
    count = newValue;
    emit valueChanged(QString::number(count));
}
