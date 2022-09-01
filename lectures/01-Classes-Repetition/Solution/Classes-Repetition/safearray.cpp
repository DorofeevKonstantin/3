#include "safearray.hpp"

#include <vector>
#include <algorithm>

void safearray::test()
{
	safearray s1(10);
	s1.fillRandom();
	s1.print();
	s1[0] = 999;
	std::cout << "s1[0]==" << s1[0] << std::endl;
	try
	{
		s1[10] = 999;
	}
	catch (const std::range_error& exception)
	{
		std::cout << "exception: " << exception.what() << std::endl;
	}
	s1.print();

	safearray s2(s1);
	s2.print();

	safearray s3;
	s3 = s2;
	s3.print();

	safearray s4;
	s4 = std::move(s3);
	s4.print();
	s3.print();

	safearray s5(std::move(s4));
	s5.print();
	s4.print();
}