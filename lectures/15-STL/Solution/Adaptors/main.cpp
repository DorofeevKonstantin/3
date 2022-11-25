#include <functional>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <valarray>
#include <iostream>

// source : https://en.cppreference.com/w/cpp/container/priority_queue

template<typename T>
void print_queue(T& q)
{
	while (!q.empty())
	{
		std::cout << q.top() << ' ';
		q.pop();
	}
	std::cout << '\n';
}

int main()
{
	//The standard container adapters are :
	//stack provides an LIFO data structure
	//queue provides a FIFO data structure
	//priority_queue provides a priority queue, which allows for constant - time lookup of the largest element(by default)
	std::priority_queue<int> q;
	const auto data = { 1,8,5,6,3,4,0,9,7,2 };
	for (int n : data)
		q.push(n);
	print_queue(q);
	std::priority_queue<int, std::vector<int>, std::greater<int>> q2(data.begin(), data.end());
	print_queue(q2);
	// Using lambda to compare elements.
	auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
	std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
	for (int n : data)
		q3.push(n);
	print_queue(q3);
	std::vector<bool> vb;
	// Pseudo containers
	// vector<bool>, bitset<size_t>, valarray

}