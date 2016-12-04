#include <iostream>
#include <boost/bind.hpp>

#include "Function.hpp"

int test1(char n)
{
    std::cout << "test1 : " << n << std::endl;
    return 0;
}

class test2
{
public:
    int operator()(char n)
    {
        std::cout << "test2 : " << n << std::endl;
        return 0;
    }
};

int main()
{
    Function<int (char)> f = &test1;
    f('c');

    Function<int (char)> f2 = boost::bind(&test1, _1);
    f2('c');

    test2 t;
    Function<int (char)> f3 = t;
    f3('c');

    f = &test1;
    f('c');

    f2 = boost::bind(&test1, _1);
    f2('c');

    f3 = t;
    f3('c');
    return 0;
}