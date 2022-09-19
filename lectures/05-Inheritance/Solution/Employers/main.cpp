#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>

class worker
{
protected:
	int baseSalary = 10'000;
	std::string name;
	std::random_device rd{};
	std::mt19937 engine{ rd() };
	std::uniform_real_distribution<double> dist{ 0.0, 100.0 };
public:
	virtual int calculateSalary() = 0;
};
class developer : public worker
{
	int hours;
	int hourPayment;
public:
	int calculateSalary() override
	{
		return baseSalary + hours * hourPayment;
	}
	developer()
	{
		hours = static_cast<int>(dist(engine));
		hourPayment = static_cast<int>(dist(engine));
	}
	~developer()
	{

	}
};
class saler : public worker
{
	int countDeals;
	int dealPayment;
public:
	int calculateSalary() override
	{
		return baseSalary + countDeals * dealPayment;
	}
	saler()
	{
		countDeals = static_cast<int>(dist(engine));
		dealPayment = static_cast<int>(dist(engine));
	}
};
class database
{
	std::vector<worker*> workers;
public:
	database(int size = 100)
	{
		workers.reserve(size);
	}
	database& add(worker* new_employee)
	{
		workers.push_back(new_employee);
		return *this;
	}
	void add(std::initializer_list<worker*> l)
	{
		for (auto w : l)
			workers.push_back(w);
	}
	int calculateAllSalary()
	{
		int summ = 0;
		for (auto current : workers)
			summ += current->calculateSalary();
		//for (auto it = workers.begin(); it != workers.end(); ++it)
		//	summ += (*it)->calculateSalary();
		return summ;
	}
};

int main()
{
	database db;
	developer *d1 = new developer, *d2 = new developer;
	saler *s1 = new saler, *s2 = new saler;
	//db.add(d1).add(d2).add(s1).add(s2);
	db.add({ d1,d2,s1,s2 });
	std::cout << db.calculateAllSalary();
	return 0;
}