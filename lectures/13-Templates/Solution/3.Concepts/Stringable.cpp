#include "Stringable.hpp"

void stringableTest()
{
	output<const char*>("Hello world!");
	output<person>(person("Ivan"));
}