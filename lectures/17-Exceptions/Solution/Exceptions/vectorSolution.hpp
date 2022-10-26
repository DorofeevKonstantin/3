#pragma once

#include <vector>

namespace KB::Vector::Solution
{
	class Storage
	{
	public:
		std::vector<std::vector<std::vector<int>>> vectors;
		// RAII
		// use smart pointers!  std::vector<std::shared_ptr<bullet>> bullets;
		Storage(int size)
		{
			try
			{
				vectors.reserve(size);
				vectors.resize(size);
				for (int i = 0; i < size; ++i)
				{
					vectors[i].reserve(size);
					vectors[i].resize(size);
					for (int j = 0; j < size; ++j)
					{
						vectors[i][j].reserve(size);
						vectors[i][j].resize(size);
						for (int k = 0; k < size; ++k)
						{
							vectors[i][j][k] = i + j + k;
						}
					}
				}
			}
			catch (std::bad_alloc& e)
			{
				std::cout << "Storage error!" << std::endl << e.what() << std::endl;
				throw e;
			}
		}
		// destructor not called for unfinished objects
		~Storage()
		{
			std::cout << "~VectorSolution" << std::endl;
		}
	};
}