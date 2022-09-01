#pragma once

namespace KB::Array::Problem
{
	class Storage
	{
	public:
		int*** mass;
		Storage(int size)
		{
			mass = new int** [size];
			for (int i = 0; i < size; ++i)
			{
				mass[i] = new int* [size];
				for (int j = 0; j < size; ++j)
				{
					mass[i][j] = new int[size];
					for (int k = 0; k < size; ++k)
					{
						mass[i][j][k] = i + j + k;
					}
				}
			}
		}
		// destructor not called for unfinished objects
		~Storage()
		{
			// delete[]
			std::cout << "~ArrayProblem" << std::endl;
		}
	};
}