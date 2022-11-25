#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <algorithm>

#include "tuple.hpp"
#include "ptrs.hpp"
#include "stl_containers.hpp"

using namespace std;

struct MyArray
{
	int* data;
	int size;
	MyArray(size_t _size) : size(_size)
	{
		data = new int[size];
	}
	~MyArray()
	{
		delete[] data;
	}
};

// stack with N elements of type T
// stack<vector>  || O*(1) || N*sizeof(T)*k
// stack<deque>   || O(1)  || N*sizeof(T) + N/chunkSize*sizeof(void*)
// stack<list>    || O(1)  || N*(sizeof(T) + 2*sizeof(void*))

// overloading? overriding?
// replacement!
// first part of new
void* operator new(size_t size)
{
	return malloc(size);
}

void* operator new[](size_t size)
{
	return malloc(size);
}

void operator delete(void* ptr, size_t size)
{
	free(ptr);
}

/////////////////////////

class person
{
public:
	std::string method() { return "123"; }
};

typedef std::string(person::* personFunPtr)();

void mySort(personFunPtr fPtr)
{

}

int main()
{
	//personFunPtr fptr = &person::method;
	//mySort(&person::method);
	//tuple_example();
	//figures_example();
	//complex_example();
	containers_example();
	return 0;
}