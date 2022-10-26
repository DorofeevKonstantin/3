#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

#include "createContainer.hpp"

void create_container_Samples()
{
	auto db = create_container<int, std::vector>(10);
	std::for_each(db.begin(), db.end(),
		[](auto& entry)
		{
			std::cout << entry << " ";
		});
	std::cout << std::endl;

	auto db2 = create_container<int, std::list>(10);
	std::for_each(db2.begin(), db2.end(),
		[](auto& entry)
		{
			std::cout << entry << " ";
		});
	std::cout << std::endl << std::endl;
}