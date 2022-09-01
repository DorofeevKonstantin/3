#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
#include <array>
#include <stack>

#include "stl_containers.hpp"

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
}