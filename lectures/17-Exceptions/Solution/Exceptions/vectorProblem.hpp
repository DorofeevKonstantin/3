#pragma once

#include <vector>

namespace KB::Vector::Problem
{
	class Storage
	{
	public:
		std::vector<std::vector<std::vector<int>>> vectors;
		Storage(int size)
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
						vectors[i][j][k] = i + j + k;
				}
			}
		}
		// destructor not called for unfinished objects
		~Storage()
		{
			std::cout << "~VectorProblem" << std::endl;
		}
	};
}