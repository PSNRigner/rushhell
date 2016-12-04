#include <iostream>
#include "Bind.hpp"

int test0()
{
    std::cout << "Test0 " << std::endl;
    return 0;
}

int test1(int n)
{
    std::cout << "Test1 " << n << std::endl;
    return 1;
}

int test2(int n1, int n2)
{
    std::cout << "Test2 " << n1 << " " << n2 << std::endl;
    return 2;
}

int test3(int n1, int n2, int n3)
{
    std::cout << "Test3 " << n1 << " " << n2 << " " << n3 << std::endl;
    return 3;
}

int test4(int n1, int n2, int n3, int n4)
{
    std::cout << "Test3 " << n1 << " " << n2 << " " << n3 << " " << n4 << std::endl;
    return 4;
}

int test5(int n1, int n2, int n3, int n4, int n5)
{
    std::cout << "Test3 " << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << std::endl;
    return 5;
}

int test6(int n1, int n2, int n3, int n4, int n5, int n6)
{
    std::cout << "Test3 " << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << " " << n6 << std::endl;
    return 6;
}

struct test_object0
{
    int operator()()
    {
        std::cout << "Test Object 0" << std::endl;
        return 7;
    }
};

struct test_object1
{
    int operator()(int n1)
    {
        std::cout << "Test Object 1 " << n1 << std::endl;
        return 8;
    }
};

struct test_object2
{
    int operator()(int n1, int n2)
    {
        std::cout << "Test Object 2 " << n1 << " " << n2 << std::endl;
        return 9;
    }
};

struct test_object3
{
    int operator()(int n1, int n2, int n3)
    {
        std::cout << "Test Object 3 " << n1 << " " << n2 << " " << n3 << std::endl;
        return 10;
    }
};

struct test_object4
{
    int operator()(int n1, int n2, int n3, int n4)
    {
        std::cout << "Test Object 4 " << n1 << " " << n2 << " " << n3 << " " << n4 << std::endl;
        return 11;
    }
};

struct test_object5
{
    int operator()(int n1, int n2, int n3, int n4, int n5)
    {
        std::cout << "Test Object 5 " << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << std::endl;
        return 12;
    }
};

struct test_object6
{
    int operator()(int n1, int n2, int n3, int n4, int n5, int n6)
    {
        std::cout << "Test Object 5 " << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << " " << n6 << std::endl;
        return 13;
    }
};

struct test_member0
{
    int test()
    {
        std::cout << "Test Member 0" << std::endl;
        return 14;
    }
};

struct test_member1
{
    int test(int n1)
    {
        std::cout << "Test Member 1 " << n1 << std::endl;
        return 15;
    }
};

struct test_member2
{
    int test(int n1, int n2)
    {
        std::cout << "Test Member 2 " << n1 << " " << n2 << std::endl;
        return 16;
    }
};

struct test_member3
{
    int test(int n1, int n2, int n3)
    {
        std::cout << "Test Member 3 " << n1 << " " << n2 << " " << n3 << std::endl;
        return 17;
    }
};

struct test_member4
{
    int test(int n1, int n2, int n3, int n4)
    {
        std::cout << "Test Member 4 " << n1 << " " << n2 << " " << n3 << " " << n4 << std::endl;
        return 18;
    }
};

struct test_member5
{
    int test(int n1, int n2, int n3, int n4, int n5)
    {
        std::cout << "Test Member 5 " << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << std::endl;
        return 19;
    }
};

struct test_member6
{
    int test(int n1, int n2, int n3, int n4, int n5, int n6)
    {
        std::cout << "Test Member 6 " << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << " " << n6 << std::endl;
        return 20;
    }
};

int main()
{
    std::cout << bind(test0)() << std::endl;
    std::cout << bind(test1, 41)() << std::endl;
    std::cout << bind(test2, 41, 42)() << std::endl;
    std::cout << bind(test3, 41, 42, 43)() << std::endl;
    std::cout << bind(test4, 41, 42, 43, 44)() << std::endl;
    std::cout << bind(test5, 41, 42, 43, 44, 45)() << std::endl;
    std::cout << bind(test6, 41, 42, 43, 44, 45, 46)() << std::endl;

    std::cout << bind<int>(test_object0())() << std::endl;
    std::cout << bind<int>(test_object1(), 41)() << std::endl;
    std::cout << bind<int>(test_object2(), 41, 42)() << std::endl;
    std::cout << bind<int>(test_object3(), 41, 42, 43)() << std::endl;
    std::cout << bind<int>(test_object4(), 41, 42, 43, 44)() << std::endl;
    std::cout << bind<int>(test_object5(), 41, 42, 43, 44, 45)() << std::endl;
    std::cout << bind<int>(test_object6(), 41, 42, 43, 44, 45, 46)() << std::endl;

    test_member0 member0;
    std::cout << bind<int>(&test_member0::test, &member0)() << std::endl;

    test_member1 member1;
    std::cout << bind<int>(&test_member1::test, &member1, 41)() << std::endl;

    test_member2 member2;
    std::cout << bind<int>(&test_member2::test, &member2, 41, 42)() << std::endl;

    test_member3 member3;
    std::cout << bind<int>(&test_member3::test, &member3, 41, 42, 43)() << std::endl;

    test_member4 member4;
    std::cout << bind<int>(&test_member4::test, &member4, 41, 42, 43, 44)() << std::endl;

    test_member5 member5;
    std::cout << bind<int>(&test_member5::test, &member5, 41, 42, 43, 44, 45)() << std::endl;

    test_member6 member6;
    std::cout << bind<int>(&test_member6::test, &member6, 41, 42, 43, 44, 45, 46)() << std::endl;

    return 0;
}