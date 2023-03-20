#include "../include/Lemon.hpp"
#include "../include/Banana.hpp"
#include "../include/Fruit.hpp"
#include "../include/FruitBox.hpp"

int main()
{
    Lemon   l;
    Banana  b;
    
    std::cout << l.getVitamins() << std::endl;
    std::cout << b.getVitamins() << std::endl;
    std::cout << l.getName() << std::endl;
    std::cout << b.getName() << std::endl;

    Fruit &f = l;
    std::cout << f.getVitamins() << std::endl;
    std::cout << f.getName() << std::endl;

    FruitBox    fbox(3);

    std::cout << "Size Box: " << fbox.getSize() << std::endl;
    std::cout << "Number Fruit inside the Box: " << fbox.nbFruit() << std::endl;
    std::cout << "Head of the linked list: " << fbox.head() << std::endl;

    fbox.putFruit(&l);
    fbox.putFruit(&b);
    std::cout << "Fruit in the Box : " << std::endl;
    while (fbox.head() != nullptr)
    {
        std::cout << fbox.head()->fruit->getName() << std::endl;
        fbox.setHead(fbox.head()->next);
    }

    std::cout << "Size Box: " << fbox.getSize() << std::endl;
    std::cout << "Number Fruit inside the Box: " << fbox.nbFruit() << std::endl;
    return 0;
}