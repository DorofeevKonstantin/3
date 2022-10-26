#include <iostream>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <exception>
#include <string>
#include <vector>
#include <stack>

#include "arrayProblem.hpp"
#include "arraySolution.hpp"
#include "vectorProblem.hpp"
#include "vectorSolution.hpp"

void handlingIOExceptions()
{
	std::ifstream inputFile;
	inputFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		inputFile.open("file.txt");
	}
	catch (std::exception const& e)
	{
		std::cerr << "File exception = " << e.what() << std::endl;
	}
	std::vector<int> v = { 0 };
	try
	{
		std::cout << v.at(200);
	}
	catch (std::out_of_range const& e)
	{
		std::cerr << "Vector out of range exception = " << e.what() << std::endl;
	}
}

void work()
{
	std::cout << "Do you wanna work without Storage?" << std::endl;
	std::string answer;
	std::cin >> answer;
	if (answer != "no")
	{
		std::cout << "Ok let's do it!" << std::endl;
		while (true)
		{
			std::getline(std::cin, answer);
			if (answer == "0")
				return;
			std::cout << answer << std::endl;
		}
	}
}

void arrayProblemExample()
{
	int size;
	std::cout << "Enter array problem storage size:" << std::endl;
	std::cin >> size;
	KB::Array::Problem::Storage s(size);
	std::cout << s.mass[size - 1][size - 1][size - 1] << std::endl;
}

void arraySolutionExample()
{
	int size;
	std::cout << "Enter array solution storage size:" << std::endl;
	std::cin >> size;
	try
	{
		KB::Array::Solution::Storage s(size);
		std::cout << s.mass[size - 1][size - 1][size - 1] << std::endl;
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << "Main error : " << e.what() << std::endl;
		work();
	}
}

void vectorProblemExample()
{
	int size;
	std::cout << "Enter vector problem storage size:" << std::endl;
	std::cin >> size;
	KB::Vector::Problem::Storage s(size);
	std::cout << s.vectors[size - 1][size - 1][size - 1] << std::endl;
}

void vectorSolutionExample()
{
	int size;
	std::cout << "Enter vector solution storage size:" << std::endl;
	std::cin >> size;
	try
	{
		KB::Vector::Solution::Storage s(size);
		std::cout << s.vectors[size - 1][size - 1][size - 1] << std::endl;
	}
	catch (std::bad_alloc& e)
	{
		std::cout << "Main error!" << std::endl << e.what() << std::endl;
		work();
	}
}

int main()
{
	srand((unsigned int)time(0));
	// A. Smal presentation slides

	// constructorProblem

	// destructorProblem	

	//handlingIOExceptions();

	//arrayProblemExample();
	//arraySolutionExample();

	//vectorProblemExample();
	//vectorSolutionExample();

	// guarantees

	system("pause");
	return 0;
}