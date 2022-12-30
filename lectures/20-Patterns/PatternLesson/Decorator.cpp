#include <iostream>

using namespace std;

class HelloWorldPrinter
{
public:
	void print(); // Print "World"
};

void HelloWorldPrinter::print()
{
	cout << "World";
}


class DecoratorOne
{
	HelloWorldPrinter HWP;
public:
	void print()
	{
		cout << "Hello ";
		HWP.print();
	}
};


class DecoratorTwo
{
	DecoratorOne HWP;
public:
	void print()
	{
		HWP.print();

		cout << ", we happy to see you." << endl;
	}

};


int DecoratorExample()
{
	DecoratorTwo dT;
	dT.print();
	// Prints "Hello World, we happy to see you."
	return 0;
}







