#include <tuple>
#include <iostream>
#include <string>
#include <utility>
#include <stdexcept>

#include "tuple.hpp"

using namespace std;

std::pair<int, int> ints;

tuple<double, char, string> get_student(int id)
{
	if (id == 0) return make_tuple(3.8, 'A', "Lisa Simpson");
	if (id == 1) return make_tuple(2.9, 'C', "Milhouse Van Houten");
	if (id == 2) return make_tuple(1.7, 'D', "Ralph Wiggum");
	throw invalid_argument("invalid id in get_student()");
}

void output(const tuple<double, char, std::string>& st)
{
	cout << get<0>(st) << " " << get<1>(st) << " " << get<2>(st) << endl;
}

void tuple_example()
{
	try
	{
		cout << "tuple_example" << endl;
		auto st1 = get_student(0);
		output(st1);
		st1 = get_student(3);
		output(st1);
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
	}
	auto entry = make_tuple(42, 3.14, string("Book"), "empty field");
	cout << get<2>(entry) << endl;
}