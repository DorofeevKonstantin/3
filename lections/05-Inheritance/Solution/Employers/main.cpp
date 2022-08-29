#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>

class Employee
{
protected:
	int base_salary = 1000;
	std::string name;
	std::random_device rd{};
	std::mt19937 engine{ rd() };
	std::uniform_real_distribution<double> dist{ 0.0, 100.0 };
public:
	virtual int calculate_salary() = 0;
};
class Developer : public Employee
{
	int extra_hours;
	int hour_payment;
	int* some;
public:
	int calculate_salary() override
	{
		return base_salary + extra_hours * hour_payment;
	}
	Developer()
	{
		extra_hours = static_cast<int>(dist(engine));
		hour_payment = static_cast<int>(dist(engine));
		some = new int[10000000];
	}
	~Developer()
	{
		delete[] some;
	}
};
class Saler : public Employee
{
	int count_deals;
	int deal_payment;
public:
	int calculate_salary() override
	{
		return base_salary + count_deals * deal_payment;
	}
	Saler()
	{
		count_deals = static_cast<int>(dist(engine));
		deal_payment = static_cast<int>(dist(engine));
	}
};
class Database
{
	std::vector<Employee*> workers;
public:
	Database(int size = 100)
	{
		workers.reserve(size);
	}
	Database& add(Employee* new_employee)
	{
		workers.push_back(new_employee);
		return *this;
	}
	void add(std::initializer_list<Employee*> l)
	{
		for (auto& worker : l)
			workers.push_back(worker);
	}
	int calculate_all_salary()
	{
		int summ = 0;
		/*for (Employee* current : workers)
			summ += current->calculate_salary();*/
		for (auto it = workers.begin(); it != workers.end(); ++it)
			summ += (*it)->calculate_salary();
		return summ;
	}
};

int main()
{
	Database db;
	Developer d1, d2;
	Saler s1, s2;
	//db.add(&d1).add(&d2).add(&s1).add(&s2);
	db.add({&d1,&d2,&s1,&s2});
	std::cout << db.calculate_all_salary();
	return 0;
}