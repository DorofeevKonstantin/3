#pragma once
#include <iostream>
#include "Pizza.h"
#include "NullPizza.h"

using namespace std;

class PizzaBuilder
{
protected:
	string topping;
	string doughtype;
	string fill;
	Form form;
public:
	PizzaBuilder() {};
	PizzaBuilder& setTopping(string _topping)
	{
		this->topping = _topping;
		return *this;
	}
	PizzaBuilder& setFilling(string _filling)
	{
		this->fill = _filling;
		return *this;
	}
	PizzaBuilder& setDough(string _doughtype)
	{
		this->doughtype = _doughtype;
		return *this;
	}
	PizzaBuilder& setForm(Form _form)
	{
		this->form = _form;
		return *this;
	}

	virtual Pizza* build()
	{
		return new Pizza(topping, fill, doughtype, form);
	}

};