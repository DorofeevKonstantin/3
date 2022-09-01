#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <algorithm>

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
// stack<list>    || O(1)  || N*(sizeof(T)+2*sizeof(void*))

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
template <class T>
void list_output(const std::list<T>& l)
{
	for (auto& el : l)
		std::cout << el << " ";
	std::cout << std::endl;
}

int main()
{
	/*MyArray m1(100);
	size_t m1_size = sizeof(m1);
	std::cout << "m1_size == " << m1_size << std::endl;*/

	/*{
		std::vector<int> v;
		v.resize(1000);
		for (size_t i = 0; i < 1000; i++)
		{
			v.push_back(i);
		}
	}*/

	/////////////////////////
	std::list<int> l = { 1,2,3,4,5,6,7,8,9 };
	// 1) insert/remove begin/end O(1) 2) =||= 3) find O(n) 4) [] not exist -> use iterators
	// Iterators : ++, --, ->, *
	std::list<int>::iterator it = std::find(l.begin(), l.end(), 9);
	l.push_front(0);
	l.insert(++it, 10);
	list_output(l);

	// 1.method size() O(1), method splice() O(n)
	// 2.method splice() O(1), method size() O(n)

	it = l.begin();
	while (it != l.end())
	{
		if (*it % 2 == 0)
			it = l.erase(it); // l.erase(it), ++it == invalidation of iterator
		else
			++it;
	}
	list_output(l);

	// Adapters
	

	return 0;
}