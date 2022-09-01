#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <list>

#include "createContainer.hpp"
#include "strategy.hpp"

int main()
{
	srand((unsigned int)time(0));

	create_container_Samples();

	strategyClientCode();
	return 0;
}