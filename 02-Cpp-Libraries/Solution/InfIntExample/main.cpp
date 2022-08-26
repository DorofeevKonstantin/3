#include <iostream>
#include <cassert>

#include "InfInt.h"

void testInfIntBounds()
{
    InfInt a = -1;
    assert(a++ == -1); assert(a++ == 0); assert(a == 1);
    assert(a-- == 1); assert(a-- == 0); assert(a == -1);
    assert(++a == 0); assert(++a == 1); assert(a == 1);
    assert(--a == 0); assert(--a == -1); assert(a == -1);

    a = UPPER_BOUND;
    assert(a++ == UPPER_BOUND); assert(a == UPPER_BOUND + 1);
    assert(a-- == UPPER_BOUND + 1); assert(a == UPPER_BOUND);
    assert(++a == UPPER_BOUND + 1); assert(a == UPPER_BOUND + 1);
    assert(--a == UPPER_BOUND); assert(a == UPPER_BOUND);
}
InfInt fib(InfInt n)
{
    InfInt pp = 0, p = 1;
    for (InfInt i = 2; i < n; ++i)
    {
        InfInt op = p;
        p += pp;
        pp = op;
    }
    return p + pp;
}
InfInt fact(InfInt n)
{
    InfInt result = 1;
    for (InfInt i = 2; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

int main()
{
    testInfIntBounds();
    std::cout << "fibonacci(100) : " << fib(100) << std::endl;
    std::cout << "fact(100) : " << fact(100) << std::endl;
    std::cout << "fact(200)*fact(300) : " << fact(200) * fact(300) << std::endl;
	return 0;
}