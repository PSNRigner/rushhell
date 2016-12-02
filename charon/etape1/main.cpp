#include <iostream>

#include "FunctionSignature.hpp"

int test0()
{
    std::cout << "test0" << std::endl;
    return 0;
}

int test1(int n)
{
    std::cout << "test1 : " << n << std::endl;
    return 0;
}

int test2(int n1, int n2)
{
    std::cout << "test2 : " << n1 << " " << n2 << std::endl;
    return 0;
}

int test3(int n1, int n2, int n3)
{
    std::cout << "test3 : " << n1 << " " << n2 << " " << n3 << std::endl;
    return 0;
}

int test4(int n1, int n2, int n3, int n4)
{
    std::cout << "test4 : " << n1 << " " << n2 << " " << n3 << " " << n4 << std::endl;
    return 0;
}

int main()
{
    FunctionSignature<int (*)()>::type f0 = &test0;
    f0();

    FunctionSignature<int (*)(int)>::type f2 = &test1;
    f2(42);

    FunctionSignature<int (*)(int, int)>::type f3 = &test2;
    f3(42, 21);

    FunctionSignature<int (*)(int, int, int)>::type f4 = &test3;
    f4(42, 21, 12);

    FunctionSignature<int (*)(int, int, int, int)>::type f5 = &test4;
    f5(42, 21, 12, 84);

    return 0;
}