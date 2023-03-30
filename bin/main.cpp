#include "../part2_Fruit/include/Lemon.hpp"
#include "../part2_Fruit/include/Banana.hpp"
#include "../part2_Fruit/include/Lime.hpp"
#include "../part2_Fruit/include/Fruit.hpp"
#include "../part2_Fruit/include/FruitBox.hpp"
#include "../part2_Fruit/include/LittleHand.hpp"
#include "../part2_Fruit/include/Coconut.hpp"

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
    std::cout << "Vitamins: " << coconut.getVitamins() << std::endl;
    std::cout << "Name: " << coconut.getName() << std::endl;

    // Create an array of coconuts
    Coconut* coconuts[] = {
        new Coconut(), new Coconut(), new Coconut(),
        new Coconut(), new Coconut(), new Coconut(),
        new Coconut(), new Coconut(), new Coconut(),
        new Coconut(), new Coconut(), new Coconut(),
        new Coconut(), new Coconut(), new Coconut(),
        new Coconut(), new Coconut(), new Coconut(),
        new Coconut(), new Coconut(), new Coconut(),
        new Coconut(), new Coconut(), new Coconut(),
        new Coconut(), nullptr
    };

    // Organize the coconuts into fruit boxes
    FruitBox const* const* coconutBoxes = LittleHand::organizeCoconut(coconuts);

    // Print the contents of the coconut boxes
    std::cout << "Organized coconut boxes:" << std::endl;
    for (int i = 0; coconutBoxes[i] != nullptr; i++) {
        std::cout << "Box " << i+1 << ": " << coconutBoxes[i]->nbFruit() << std::endl;
    }

    // Clean up memory
    for (int i = 0; coconuts[i] != nullptr; i++) {
        delete coconuts[i];
    }
    for (int i = 0; coconutBoxes[i] != nullptr; i++) {
        delete coconutBoxes[i];
    }
    delete[] coconutBoxes;

    return 0;
}