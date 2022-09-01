#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// only declaration
template <class T>
struct Storage;

// full definiton for T==char
template <>
struct Storage<char>
{
	int size;
	std::string data;
	Storage(int _size) : size(_size)
	{
		data.resize(size);
	}
};

int main()
{
	Storage<int> di(10); // can't compile
	Storage<double> dd(1); // can't compile

	Storage<char> dc(100);
	dc.data[5] = 'A';
	return 0;
}