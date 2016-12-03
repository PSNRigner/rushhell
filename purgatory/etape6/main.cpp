#include <iostream>

#include "Matcher.hpp"

int main()
{
    Matcher matcher("(mechant)|(criminel)");
    int nbr = 0;
    std::cout << matcher.find("mechant", nbr) << std::endl;
    std::cout << nbr << std::endl;
    std::cout << matcher.find("criminel") << std::endl;
    std::cout << matcher.find("mechantmechant", nbr) << std::endl;
    std::cout << nbr << std::endl;
    return 0;
}