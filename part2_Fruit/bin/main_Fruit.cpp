#include "../include/Lemon.hpp"
#include "../include/Banana.hpp"
#include "../include/Lime.hpp"
#include "../include/Fruit.hpp"
#include "../include/FruitBox.hpp"
#include "../include/LittleHand.hpp"
#include "../include/Coconut.hpp"

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
    fbox.printList();

    fbox.pickFruit();
    fbox.printList();
    fbox.pickFruit();
    fbox.printList();

    Lime   lime;
    std::cout << "new Lime Fruit:" << std::endl;
    std::cout << lime.getVitamins() << std::endl;
    std::cout << lime.getName() << std::endl;

    Lime    lime2, lime3, lime4;
    Lemon   lemon, lemon2;
    Banana  banana, banana2;

    FruitBox    unsorted(15);
    FruitBox    LimeFruitBox(3);
    FruitBox    LemonFruitBox(3);
    FruitBox    BananaFruitBox(3);

    unsorted.putFruit(&lime);
    unsorted.putFruit(&lime2);
    unsorted.putFruit(&lime3);
    unsorted.putFruit(&lime4);

    unsorted.putFruit(&lemon);
    unsorted.putFruit(&lemon2);

    unsorted.putFruit(&banana);
    unsorted.putFruit(&banana2);

    unsorted.printList();

    LittleHand  littleHand;
    littleHand.sortFruitBox(unsorted, LemonFruitBox, BananaFruitBox, LimeFruitBox);

    std::cout << "display List after sort:" << std::endl;
    std::cout << "unsorted list:" << std::endl;
    unsorted.printList();
    std::cout << "LemonFruitBox list:" << std::endl;
    LemonFruitBox.printList();
    std::cout << "BananaFruitBox list:" << std::endl;
    BananaFruitBox.printList();
    std::cout << "LimeFruitBox list:" << std::endl;
    LimeFruitBox.printList();

    Coconut     coconut;
    std::cout << "new Coconut Fruit:" << std::endl;
    std::cout << coconut.getVitamins() << std::endl;
    std::cout << coconut.getName() << std::endl;
    return 0;
}