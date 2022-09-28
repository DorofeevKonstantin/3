#include <iostream>
#include <string>

using namespace std;

struct person
{
	std::string name;
	int id;
	~person() {}
};

class scopedPtr
{
private:
	person* p;
public:
	scopedPtr() = delete;
	scopedPtr(const scopedPtr& obj) = delete;
	scopedPtr(person* _p) : p(_p) {}
	~scopedPtr() { delete p; }
	person* operator->() { return p; }
};

class sharedPtr
{
private:
	struct storage
	{
		person* p;
		int count;
		~storage()
		{
			delete p;
		}
	};
	storage* s;
public:
	sharedPtr() = delete;
	sharedPtr(person* _p)
	{
		s = new storage;
		s->p = _p;
		s->count = 1;
	}
	sharedPtr& operator=(const sharedPtr& obj)
	{
		if (this->s == obj.s)
			return *this;
		this->s->count--;
		if (this->s->count == 0)
			delete this->s;
		this->s = obj.s;
		this->s->count++;
		return *this;
	}
	sharedPtr(const sharedPtr& obj)
	{
		this->s = obj.s;
		this->s->count++;
	}
	person* operator->() { return s->p; }
	~sharedPtr()
	{
		this->s->count--;
		if (this->s->count == 0)
			delete this->s;
	}
};

void sharedPtrTest(sharedPtr instance)
{
	instance->id = 1;
	// call ~sharedPtr
}

int main()
{
	scopedPtr scPtr = new person;
	// work with person
	scPtr->id = 1;

	sharedPtr shPtr = new person;
	// work with person
	shPtr->id = 1;
	sharedPtrTest(shPtr);

	// call ~scopedPtr -> call delete p -> call ~person
	// call ~sharedPtr -> ...
	return 0;
}