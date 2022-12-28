#include <iostream>
using namespace std;

#include "Pizza.h"
#include "PizzaBuilder.h"
#include "AbstractFactory.hpp"

int DecoratorExample();

int main()
{
	DecoratorExample();

	cout << "\n\n" << endl;

	PizzaBuilder* PB = new SquarePizzaFactory();
	PB->setDough("Testo").setFilling("salami").setTopping("cheese");

	Pizza* newPizza = PB->build();
	Pizza* mySpecialPizza = newPizza->clone();

	cout << "Original Pizza: " << endl;
	newPizza->printPizzaInfo();

	cout << "Cloned Pizza: " << endl;
	mySpecialPizza->printPizzaInfo();

	PB->setFilling("ananas");

	cout << "Null Pizza: " << endl;
	Pizza* nullpizza = PB->build();

	nullpizza->printPizzaInfo();
}