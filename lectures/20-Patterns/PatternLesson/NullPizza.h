#pragma once
#include "Pizza.h"

class NullPizza : public Pizza
{
public:
	NullPizza(string _topping, string _fill, string _dough, Form _form) : Pizza(_topping, _fill, _dough, _form) {}
	void printPizzaInfo() override
	{
		cout << "This pizza is null."; // or this method can be full empty.
	}

};