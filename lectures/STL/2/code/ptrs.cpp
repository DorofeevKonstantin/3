#include <iostream>
#include <vector>
#include <memory>

#include "ptrs.hpp"

using namespace std;

class Complex
{
public:
	double Re;
	double Im;
	Complex(double Re_, double Im_) :Re(Re_), Im(Im_)
	{
	}
	void output()
	{
		cout << Re << "+" << Im << "i" << endl;
	}
};

// interface
class Figure
{
public:
	virtual void func() = 0;
	virtual ~Figure() {};
};

class Line : public Figure
{
public:
	void func()
	{
		std::cout << "line" << std::endl;
	}
	Line()
	{
		std::cout << "line()" << std::endl;
	}
	~Line()
	{
		std::cout << "~line" << std::endl;
	}
};
class Polygon : public Figure
{
public:
	void func()
	{
		std::cout << "polygon" << std::endl;
	}
	Polygon()
	{
		std::cout << "polygon()" << std::endl;
	}
	~Polygon()
	{
		std::cout << "~polygon" << std::endl;
	}
};

void figures_example()
{
	int choise = 1, count = 0;
	std::vector<std::unique_ptr<Figure>> v;
	while (choise != 0)
	{
		std::cout << "Enter Line/Polygon?";
		std::cin >> choise;
		switch (choise)
		{
		case 1:
			v.push_back(std::unique_ptr<Line>(new Line()));
			break;
		case 2:
			v.push_back(std::unique_ptr<Polygon>(new Polygon()));
			break;
		default:
			break;
		}
	}
	std::cout << "size=" << v.size() << std::endl;
	for (auto& my : v)
	{
		std::cout << "v[" << count << "]:";
		my->func();
		++count;
	}
}

void complex_example()
{
	Complex* c = new Complex(1, 1);
	c->output();
	delete c;
	unique_ptr<Complex> uptr = make_unique<Complex>(2, 4);
	uptr->output();
	shared_ptr<Complex> sp;
	{
		sp.reset(new Complex(1, 1));
		sp->output();
		//sp = 0;
	}
	weak_ptr<Complex> wp = sp;
	shared_ptr<Complex> sp2 = wp.lock();
	
	if (sp2)
		sp2->output();
}