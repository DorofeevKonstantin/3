#include <string>
#include <vector>
#include <iostream>

int main()
{
	// https://en.wikipedia.org/wiki/Criticism_of_C%2B%2B
	// https://en.wikipedia.org/wiki/Argument-dependent_name_lookup#Criticism
	// https://yosefk.com/c++fqa/web-vs-c++.html
	// https://medium.com/nerd-for-tech/linus-torvalds-c-is-really-a-terrible-language-2248b839bee3

	/*int x, y(int), z;
	x* y(z);*/
	/*struct x { x(int) {} } *z;
	x* y(z);*/

	/*std::vector<std::string> text();
	text.push_back("123");*/
	return 0;
}