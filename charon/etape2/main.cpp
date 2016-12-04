#include <iostream>
#include <boost/bind.hpp>

#include "Function.hpp"

int test1(int n)
{
    std::cout << "test1 : " << n << std::endl;
    return 0;
}

class test2
{
public:
    int operator()(int n)
    {
        std::cout << "test2 : " << n << std::endl;
        return 0;
    }
};

int main()
{
    Function<int (int)> f = &test1;
    f(42);

    Function<int (int)> f2 = boost::bind(&test1, _1);
    f2(42);

    test2 t;
    Function<int (int)> f3 = t;
    f3(42);
    return 0;
}