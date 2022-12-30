#pragma once
#include "PizzaBuilder.h"

class SquarePizzaFactory : public PizzaBuilder
{
public:
	Pizza* build() override
	{
		if (fill == "ananas")
		{
			return new NullPizza(topping, fill, doughtype, Form("nullform"));
		}
		else return new Pizza(topping, fill, doughtype, Form("Square"));
	}
};

class TorusPizzaFactory : public PizzaBuilder
{
public:
	TorusPizzaFactory() {};
	Pizza* build() override
	{
		if (fill == "ananas")
		{
			return new NullPizza(topping, fill, doughtype, Form("nullform"));
		}
		else return new Pizza(topping, fill, doughtype, Form("Torus"));
	}
};
