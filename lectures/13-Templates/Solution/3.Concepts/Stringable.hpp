#include <iostream>
#include <concepts>
#include <vector>
#include <string>
#include <algorithm>

class person
{
private:
	std::string name;
public:
	person(std::string _name = "") : name(_name) {}
	operator const std::string&() const
	{
		return name;
	}
};

template<class T>
concept stringable = requires(T obj)
{
	{ obj } -> std::convertible_to<std::string>;
};

template<class T>
void output(T obj) requires stringable<T>
{
	std::cout << typeid(obj).name() << " as string : "
		<< std::string(obj) << std::endl;
}

void stringableTest();