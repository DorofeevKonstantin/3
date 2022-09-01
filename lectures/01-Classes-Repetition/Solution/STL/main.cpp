#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

void output(const std::vector<int>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> v;
	std::ifstream in;
	in.open("input.txt", std::ios_base::in);
	int value;
	while (in >> value)
		v.push_back(value);
	output(v);
	std::sort(v.begin(), v.end());
	output(v);
	auto last = std::unique(v.begin(), v.end());
	v.erase(last, v.end());
	output(v);
	return 0;
}