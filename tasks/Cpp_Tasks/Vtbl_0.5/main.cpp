#include <iostream>
#include "Workers.h"
using namespace std;
int main()
{
	char choise;
	while (true)
	{
		cout << "'a' add worker"
				"\n'd' display workers"
				"\n'w' write to file"
				"\n'r' read from file"
				"\n'x' exit"
				"\n Enter choise: ";
		cin >> choise;
		switch (choise)
		{
		case 'a':
			Employee::add(); 
			break;
		case 'd':
			Employee::display(); 
			break;
		case 'w':
			Employee::write(); 
			break;
		case 'r':
			Employee::read(); 
			break;
		case 'x': 
			exit(0);
		default: 
			cout << "\n unknown";
		}
	}
	return 0;
}