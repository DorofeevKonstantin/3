#include <iostream>
#include <string>

class person
{
public:
	person(size_t id_, std::string name_) : id(id_), name(name_) {}
	void print() { std::cout << id << " " << name << std::endl; }
private:
	short id;
	std::string name;
};

int main()
{
	person* p = new person(1, "Ivan");
	p->print();
	char* bytes = reinterpret_cast<char*>(p);
	*bytes = 2;
	++bytes;
	*bytes = 3;
	bytes += 15;
	*bytes = 'i';
	p->print();
	return 0;
}