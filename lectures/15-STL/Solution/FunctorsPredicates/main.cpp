#include <map>
#include <string>
#include <utility>
#include <iostream>
#include <functional>

struct point
{
	int x;
	int y;
};

template <class keyT, class valueT, class predT>
void fillMap(std::map<keyT, valueT, predT>& m)
{
	m.insert(std::make_pair("d2", point{ 2,1 }));
	m.insert(std::make_pair("a444", point{ 2,5 }));
	m.insert(std::make_pair("c33", point{ 20,1 }));
	m.insert(std::make_pair("b", point{ 20,5 }));
}

template <class keyT, class valueT, class predT>
void outputMap(const std::map<keyT, valueT, predT>& m, const std::string& name = "Map")
{
	std::cout << name << std::endl;
	for (auto& p : m)
	{
		std::cout << p.first << "->" << p.second.y << "," << p.second.x << std::endl;
	}
	std::cout << std::endl;
}

struct stringComp
{
	bool operator()(const std::string& lhs, const std::string& rhs) const
	{
		return rhs < lhs;
	}
};

template <class keyT, class valueT>
using kbMapT = std::map<keyT, valueT, std::function<bool(const keyT& lhs, const keyT& rhs)>>;

int main()
{
	std::map<std::string, point> m1;
	fillMap(m1);
	outputMap(m1, "m1");

	std::map<std::string, point, stringComp> m2;
	fillMap(m2);
	outputMap(m2, "m2");

	kbMapT<std::string, point> m3{
		[](const std::string& lhs, const std::string& rhs) { return lhs.length() < rhs.length(); }
	};
	fillMap(m3);
	outputMap(m3, "m3");

	kbMapT<std::string, point> m4{
		[](const std::string& lhs, const std::string& rhs) { return lhs.length() > rhs.length(); }
	};
	fillMap(m4);
	outputMap(m4, "m4");
}