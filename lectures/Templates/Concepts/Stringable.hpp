#include <iostream>
#include <concepts>
#include <vector>
#include <string>
#include <algorithm>

class Person
{
private:
	std::string name;
public:
	Person(std::string _name = "") : name(_name) {}
	operator const std::string&() const
	{
		return name;
	}
};

template<class T>
concept Stringable = requires(T obj)
{
	{ obj } -> std::convertible_to<std::string>;
};

template<class T>
void output(T obj) requires Stringable<T>
{
	std::cout << typeid(obj).name() << " as string : "
		<< std::string(obj) << std::endl;
}

void stringableExample();