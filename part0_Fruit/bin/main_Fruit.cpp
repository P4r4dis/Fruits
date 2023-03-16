#include "../include/Lemon.hpp"
#include "../include/Banana.hpp"

#include <iostream>

int main()
{
    Lemon   l;
    Banana  b;
    
    std::cout << l.getVitamins() << std::endl;
    std::cout << b.getVitamins() << std::endl;
    std::cout << l.getName() << std::endl;
    std::cout << b.getName() << std::endl;
    return 0;
}