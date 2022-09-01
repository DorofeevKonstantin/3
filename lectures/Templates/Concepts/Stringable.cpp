#include "Stringable.hpp"

void stringableExample()
{
	output<const char*>("Hello world!");
	output<Person>(Person("Ivan"));
}