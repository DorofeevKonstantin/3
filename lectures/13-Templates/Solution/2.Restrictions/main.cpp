#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// only declaration
template <class T>
struct storage;

// specialization for T==char
template <>
struct storage<char>
{
	int size;
	std::string data;
	storage(int _size) : size(_size)
	{
		data.resize(size);
	}
};

int main()
{
	//storage<int> di(10); // can't compile
	//storage<double> dd(1); // can't compile
	storage<char> dc(100);
	dc.data[5] = 'A';
	return 0;
}