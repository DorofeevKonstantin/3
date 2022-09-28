#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class badIndex : public std::exception
{
public:
	const char* what() const
	{
		return "EXCEPTION BadIndex.";
	}
};

template <class T>
class safeArray
{
private:
	unsigned int size;
	T* data;
public:
	safeArray() :size(0)
	{
		data = nullptr;
	}
	safeArray(unsigned int size_);

	safeArray(const safeArray& object)
	{
		size = object.size;
		data = new T[size];
		for (unsigned int i = 0; i < size; i++)
			data[i] = object.data[i];
	}
	const T& operator[](unsigned int index) const
	{
		if (index < size)
			return data[index];
		else
		{
			throw badIndex();
		}
	}
	T& operator[](unsigned int index)
	{
		if (index < size)
			return data[index];
		else
		{
			throw badIndex();
		}
	}
	safeArray& operator= (const safeArray& object)
	{
		if (this == &object) return *this;
		size = object.size;
		if (data != nullptr)
		{
			delete[] data;
		}
		data = new T[size];
		for (unsigned int i = 0; i < size; i++)
			data[i] = object.data[i];
		return *this;
	}
	void output();
};

// definition of method outside of class declaration
template <class T>
void safeArray<T>::output()
{
	for (unsigned int i = 0; i < size; i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
}

// definition of method outside of class declaration
template <class T>
safeArray<T>::safeArray(unsigned int _size)
{
	size = _size;
	data = new T[size];
}

// declaration of class
template <typename T, typename V> struct mypair;

// declaration of function
template <typename T, typename V> std::ostream& operator<<(std::ostream& os, const mypair<T, V>& obj);

// definition of class
template <typename T, typename V>
struct mypair
{
	T first;
	V second;
	friend std::ostream& operator<< <>(std::ostream& os, const mypair<T, V>& obj);
};

// not a class method, just a global function
template <typename T, typename V>
std::ostream& operator<< <>(std::ostream& os, const mypair<T, V>& obj)
{
	os << obj.first << " " << obj.second << std::endl;
	return os;
}

template <class T, class V>
class dataBase
{
private:
	std::vector<mypair<T, V>> students;
	static mypair<T, V> best_student;
public:
	void add(mypair<T, V> student)
	{
		students.push_back(student);
		if (student.second > best_student.second)
			best_student = student;
	}
	void output()
	{
		for_each(students.begin(), students.end(), [](auto& student)
			{
				std::cout << student.first << " " << student.second << std::endl;
			});
	}
	static mypair<T, V> get_best_student()
	{
		return best_student;
	}
};

// definition of static field of class dataBase
template <class T, class V>
mypair<T, V> dataBase<T, V>::best_student{ T(), V() };

int main()
{
	dataBase<std::string, int> db;
	db.add({ "Ivanov", 2 });
	db.add({ "Petrov", 33 });
	auto best_student1 = dataBase<std::string, int>::get_best_student();
	std::cout << best_student1;
	// analog : call for global function "operator<<"
	operator<< <std::string, int>(std::cout, best_student1);

	dataBase<std::string, std::string> db2;
	db2.add({ "Ivanov", "2" });
	db2.add({ "Petrov", "1" });
	auto best_student2 = dataBase<std::string, std::string>::get_best_student();
	std::cout << best_student2;

	dataBase<std::string, int> db3;
	db3.add({ "Abc", 2 });
	db3.add({ "Komarov", 44 });

	auto best_student3 = dataBase<std::string, int>::get_best_student();
	std::cout << best_student3;

	best_student2 = dataBase<std::string, std::string>::get_best_student();
	std::cout << best_student2;
	return 0;
}