#pragma once

#include <iostream>
#include <exception>

namespace KB::Array::Solution
{
	class Storage
	{
	public:
		int*** mass;
		Storage(int size)
		{
			int i, j, k;
			int i_c, j_c;
			try
			{
				mass = new int** [size];
				for (i = 0; i < size; ++i)
				{
					mass[i] = new int* [size];
					for (j = 0; j < size; ++j)
					{
						mass[i][j] = new int[size];
						for (k = 0; k < size; ++k)
							mass[i][j][k] = i + j + k;
					}
				}
			}
			catch (const std::bad_alloc& e)
			{
				std::cout << "Storage error : " << e.what() << std::endl;
				std::cout << "i==" << i << " j==" << j << std::endl;
				// watch memory profiling
				for (i_c = 0; i_c < i; ++i_c)
				{
					for (j_c = 0; j_c < size; ++j_c)
						delete[] mass[i_c][j_c];
					delete[] mass[i_c];
				}
				if (mass[i])
					for (j_c = 0; j_c < j; ++j_c)
						delete[] mass[i][j_c];
				delete[] mass;
				throw e;
			}
		}
		// destructor not called for unfinished objects
		~Storage()
		{
			std::cout << "~ArraySolution" << std::endl;
		}
	};
}