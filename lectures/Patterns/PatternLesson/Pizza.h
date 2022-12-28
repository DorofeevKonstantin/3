#pragma once
#include <iostream>
using namespace std;

class Form
{
	string form;
public:
	string getForm() { return form; };
	Form() {};
	Form(string _form) : form(_form) {}
};

class Pizza
{
	Form form;
	string topping;
	string doughtype;
	string fill;
public:
	Pizza() {}; // {...}
	Pizza(const Pizza& rhs) 
	{
		this->form = rhs.form;
		this->topping = rhs.topping;
		this->doughtype = rhs.doughtype;
		this->fill = rhs.fill;
	};
	Pizza(string _topping, string _fill, string _dough, Form _form) : 
		topping(_topping), doughtype(_dough), fill(_fill), form(_form)
	{

	}
	~Pizza() {}; // {...}

	Pizza& setTopping(string _topping)
	{
		this->topping = _topping;
		return *this;
	}
	Pizza& setFilling(string _filling)
	{
		this->fill = _filling;
		return *this;
	}
	Pizza& setDough(string _dough)
	{
		this->doughtype = _dough;
		return *this;
	}

	// Pattern NullPizza example
	virtual void printPizzaInfo() 
	{
		cout << "Pizza has " << form.getForm() << " form and " << doughtype
			 << " dough and topping " << topping << " and filled with " << fill << endl;
	}

	// Pattern Prototype example
	Pizza* clone()
	{
		return new Pizza(*this);
	}
};