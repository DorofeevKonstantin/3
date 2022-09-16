#include <iostream>
#include <string>

using namespace std;

struct Person
{
	std::string name;
	int id;
	~Person() {}
};

class Scoped_Ptr
{
private:
	Person* p;
public:
	Scoped_Ptr() = delete;
	Scoped_Ptr(const Scoped_Ptr& obj) = delete;
	Scoped_Ptr(Person* _p) : p(_p) {}
	~Scoped_Ptr() { delete p; }
	Person* operator->() { return p; }
};

class Shared_Ptr
{
private:
	struct Storage
	{
		Person* p;
		int count;
		~Storage()
		{
			delete p;
		}
	};
	Storage* storage;
public:
	Shared_Ptr() = delete;
	Shared_Ptr(Person* _p)
	{
		storage = new Storage;
		storage->p = _p;
		storage->count = 1;
	}
	Shared_Ptr& operator=(const Shared_Ptr& obj)
	{
		if (this->storage == obj.storage)
			return *this;
		this->storage->count--;
		if (this->storage->count == 0)
			delete this->storage;
		this->storage = obj.storage;
		this->storage->count++;
		return *this;
	}
	Shared_Ptr(const Shared_Ptr& obj)
	{
		this->storage = obj.storage;
		this->storage->count++;
	}
	Person* operator->() { return storage->p; }
	~Shared_Ptr()
	{
		this->storage->count--;
		if (this->storage->count == 0)
		{
			delete this->storage;
		}
	}
};

void ptr_test(Shared_Ptr shared_ptr)
{
	shared_ptr->id = 1;
	// call ~Shared_Ptr
}


int main()
{
	Scoped_Ptr scoped_ptr = new Person;
	// work with Person
	scoped_ptr->id = 1;

	Shared_Ptr shared_ptr = new Person;
	// work with Person
	shared_ptr->id = 1;
	ptr_test(shared_ptr);

	// call ~Scoped_Ptr -> call delete p -> call ~Person
	// call ~Shared_Ptr
	return 0;
}