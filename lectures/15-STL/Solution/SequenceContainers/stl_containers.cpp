#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
#include <array>
#include <stack>

#include "stl_containers.hpp"

template <class T>
void list_output(const std::list<T>& l)
{
	for (auto& el : l)
		std::cout << el << " ";
	std::cout << std::endl;
}

void containers_example()
{
	// Standard Template Library :  Containers <-> Iterator <-> Algorithm
	// Sequence containers

	// vector
	std::vector<int> v;
	// 1) Add/Remove to the back == O*(1)
	// 2) Insert/Remove from begin / middle positions == O(n)
	// 3) Find == O(n)
	// 4) Random access : YES, [], at()
	v.reserve(1000);
	for (size_t i = 0; i < 1000; i++)
		v.push_back(i);
	// swap trick
	std::vector<int>(v).swap(v);
	// normal way
	v.shrink_to_fit();


	// deque
	std::deque<int> d; //double ended queue ~ list? // двусвязный список подмассивов
	// 1) Add/Remove to the back && front  == O*(1)
	// 2) Insert/Remove from middle positions == O(n)
	// 3) Find == O(n)
	// 4) Random access : YES, [], at() == slower than vector
	d.push_front(2);
	d.push_front(1);
	d.push_back(3);
	d.push_back(4);
	// Analyze memory using vector vs deque ?
	// Examples of deque using : stack, Browser history, flow scheduling algorithm


	// string, wstring     ?? COW (copy on write) / ленивое/отложенное копирование ??
	std::string s;
	s += "123";
	std::string s1 = "abc";
	std::string s2 = s1;
	s2[0] = 'A'; // need copy
	// find(), substr(), c_str()


	// list
	std::list<int> l = { 1,2,3,4,5,6,7,8,9 };
	// 1) insert/remove begin/end O(1) 2) =||= 3) find O(n) 4) [] not exist -> use iterators
	// Iterators : ++, --, ->, *
	std::list<int>::iterator it = std::find(l.begin(), l.end(), 4);
	//l.push_front(0);
	l.insert(++it, 12);
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
}