#include <iostream>
#include <concepts>
#include <string>
#include <algorithm>

class Person
{
protected:
	std::string name;
	int age;
public:
	Person(std::string _name = "", int _age = 0) : name(_name), age(_age) {}
	virtual void output()
	{
		std::cout << name << " " << age << std::endl;
	}
	virtual ~Person()
	{
		std::cout << "~Person : " << name << " called" << std::endl;
	}
};

class Manager : public Person
{
private:
	int experience;
public:
	Manager(std::string _name = "", int _age = 0, int _experience = 0) : Person(_name, _age), experience(_experience) {}
	void output() override
	{
		Person::output();
		std::cout << experience << std::endl;
	}
	~Manager()
	{
		std::cout << "~Manager : " << name << " called" << std::endl;
	}
};

// https://en.cppreference.com/w/cpp/language/value_category

int main()
{
	Person* p = new Person("Mihail", 25);
	p->output();
	Manager* m = dynamic_cast<Manager*>(p);
	if (m)
		m->output();
	else
		std::cout << "m is not valid pointer" << std::endl;
	delete p;
	m = new Manager("Olga", 18, 2);
	p = dynamic_cast<Person*>(m);
	if (p)
	{
		p->output();
		delete p;
	}
	else
	{
		std::cout << "p is not valid pointer" << std::endl;
		delete m;
	}
	return 0;
}