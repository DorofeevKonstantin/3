#include "Nodable.hpp"

void gcd_examples()
{
	int left = 320, right = 128;
	output_gcd<int>(left, right);

	left = 30, right = 18;
	output_gcd<int>(left, right);

	string_ext ls = "ABABAB", rs = "AB";
	output_gcd<string_ext>(ls, rs);

	ls = "ABCD123ABCDfgHH", rs = "BCD";
	output_gcd<string_ext>(ls, rs);

	ls = "~!@*", rs = "Hello, world!";
	output_gcd<string_ext>(ls, rs);

	ls = " AB05671CDFSDFSDF ", rs = "11111111111 111 111111111111671111111 111111";
	_ASSERT(gcd<string_ext>(ls, rs) == string_ext("671"));
	output_gcd<string_ext>(ls, rs);
}