#include <iostream>
#include <ctime>
#include <algorithm>
#include <unordered_map>

struct Person
{
	int age;
	int id;
	std::string name;
	friend std::ostream& operator<<(const std::ostream& os, const Person& obj);
};
std::ostream& operator<<(std::ostream& os, const Person& obj)
{
	os << obj.age << "," << obj.id << "," << obj.name;
	return os;
}
bool operator==(const Person& lhs, const Person& rhs)
{
	return (lhs.id == rhs.id);
}
// std::hash for out type
template<> struct std::hash<Person>
{
	std::size_t operator()(Person const& p) const noexcept
	{
		std::size_t ageHash = std::hash<int>{}(p.age);
		std::size_t idHash = std::hash<int>{}(p.id);
		std::size_t nameHash = std::hash<std::string>{}(p.name);
		return ageHash ^ (idHash << 2) ^ (nameHash >> 5);
	}
};

template <class key_t, class value_t>
void outputMap(const std::unordered_map<key_t, value_t>& um)
{
	std::cout << "unordered_map : " << std::endl;
	for (auto& elem : um)
	{
		std::cout << elem.first << " -> " << elem.second << std::endl;
	}
}

void standartExample()
{
	std::unordered_map<int, std::string> um = { {1,"one"}, {2,"two"}, {3,"three"} };
	outputMap(um);
}

void hashNonstandartType()
{
	std::unordered_map<Person, std::string> um =
	{ {{20,1,"Ivan"},"phd"}, {{21,2,"Petr"},"student"}, {{18,3,"Elena"},"assistant"} };
	outputMap(um);
}

int main()
{
	// c++ std::hash micrisoft implementation : https://ru.wikipedia.org/wiki/FNV
	// FNV_32_PRIME = 0x01000193
	size_t hash0 = std::hash<std::string>()("123");

	standartExample();

	hashNonstandartType();

	return 0;
}