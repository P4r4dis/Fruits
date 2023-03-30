#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_Lemon.hpp"
#include "../test_include/test_Banana.hpp"
#include "../test_include/test_Lime.hpp"
#include "../test_include/test_FruitBox.hpp"
#include "../test_include/test_LittleHand.hpp"
#include "../test_include/test_Coconut.hpp"

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Lemon, test_Lemon_class, .init = redirect_all_stdout)
{
    Lemon   l;

    cr_assert(l.getVitamins() == 3);
    l.setVitamins(4);
    cr_assert(l.getVitamins() != 3);

    cr_assert(l.getName() == "lemon");
    l.getName() = "G";
    cr_assert(l.getName() != "G");

    l.setVitamins(3);
    std::cout << l.getVitamins() << std::endl;
    std::cout << l.getName() << std::endl;
    cr_assert_stdout_eq_str(
        "3\n"
        "lemon\n");
}

Test(Banana, test_Banana_class, .init = redirect_all_stdout)
{
    Banana   b;

    cr_assert(b.getVitamins() == 5);
    b.setVitamins(4);
    cr_assert(b.getVitamins() != 5);

    cr_assert(b.getName() == "banana");
    b.getName() = "G";
    cr_assert(b.getName() != "G");

    b.setVitamins(5);
    std::cout << b.getVitamins() << std::endl;
    std::cout << b.getName() << std::endl;
    cr_assert_stdout_eq_str(
        "5\n"
        "banana\n");
}

Test(Fruit, test_Fruit_class, .init = redirect_all_stdout)
{
    Lemon   l;
    Fruit &f = l;

    std::cout << f.getVitamins() << std::endl;
    std::cout << f.getName() << std::endl;
    cr_assert_stdout_eq_str(
        "3\n"
        "lemon\n");
}

Test(FruitBox, test_FruitBox_class, .init = redirect_all_stdout)
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

    cr_assert(fbox.getSize() == 3);
    cr_assert(fbox.nbFruit() == 0);
    cr_assert(fbox.head() == nullptr);

    cr_assert_stdout_eq_str(
        "3\n"
        "5\n"
        "lemon\n"
        "banana\n"
        "3\n"
        "lemon\n");
}

Test(FruitBox, test_FruitBox_putFruit, .init = redirect_all_stdout)
{
    Lemon   l;
    Banana  b;
    Banana  c;
    Lemon   d;

    
    std::cout << l.getVitamins() << std::endl;
    std::cout << b.getVitamins() << std::endl;
    std::cout << l.getName() << std::endl;
    std::cout << b.getName() << std::endl;

    Fruit &f = l;
    std::cout << f.getVitamins() << std::endl;
    std::cout << f.getName() << std::endl;

    FruitBox    fbox(3);

    cr_assert(fbox.getSize() == 3);
    cr_assert(fbox.nbFruit() == 0);
    cr_assert(fbox.head() == nullptr);
    cr_assert(fbox.putFruit(&l) == true);
    cr_assert(fbox.nbFruit() == 1);
    cr_assert(fbox.putFruit(&b) == true);
    cr_assert(fbox.nbFruit() == 2);
    cr_assert(fbox.putFruit(&c) == true);
    cr_assert(fbox.nbFruit() == 3);
    cr_assert(fbox.putFruit(&d) == false);
    cr_assert(fbox.nbFruit() == 3);
    cr_assert(fbox.putFruit(&f) == false);
    cr_assert(fbox.nbFruit() == 3);
    cr_assert(fbox.head() != nullptr);

    std::cout << "Fruit in the Box : " << std::endl;
    while (fbox.head() != nullptr)
    {
        std::cout << fbox.head()->fruit->getName() << std::endl;
        fbox.setHead(fbox.head()->next);
    }
}


Test(FruitBox, test_FruitBox_pickFruit, .init = redirect_all_stdout)
{
    Lemon   l;
    Banana  b;
    Banana  c;
    Lemon   d;

    
    std::cout << l.getVitamins() << std::endl;
    std::cout << b.getVitamins() << std::endl;
    std::cout << l.getName() << std::endl;
    std::cout << b.getName() << std::endl;

    Fruit &f = l;
    std::cout << f.getVitamins() << std::endl;
    std::cout << f.getName() << std::endl;

    FruitBox    fbox(3);

    cr_assert(fbox.putFruit(&l) == true);
    cr_assert(fbox.putFruit(&b) == true);
    cr_assert(fbox.putFruit(&c) == true);
    cr_assert(fbox.putFruit(&d) == false);
    fbox.printList();

    cr_assert(fbox.pickFruit() == &l);
    cr_assert(fbox.pickFruit() == &b);
    cr_assert(fbox.pickFruit() == &c);
    cr_assert(fbox.pickFruit() == nullptr);

    fbox.printList();
    cr_assert(fbox.head() == nullptr);
}

Test(Lime, test_Lime_class, .init = redirect_all_stdout)
{
    Lime   lime;

    cr_assert(lime.getVitamins() == 2);
    lime.setVitamins(4);
    cr_assert(lime.getVitamins() != 3);

    cr_assert(lime.getName() == "lime");
    lime.getName() = "G";
    cr_assert(lime.getName() != "G");

    lime.setVitamins(2);
    std::cout << lime.getVitamins() << std::endl;
    std::cout << lime.getName() << std::endl;
    cr_assert_stdout_eq_str(
        "2\n"
        "lime\n");
}

Test(LittleHand, test_LittleHand_unsorted, .init = redirect_all_stdout)
{
    Lime    lime, lime2, lime3, lime4;
    Lemon   lemon, lemon2;
    Banana  banana, banana2;

    FruitBox    unsorted(8);
    FruitBox    LimeFruitBox(3);
    FruitBox    LemonFruitBox(3);
    FruitBox    BananaFruitBox(3);

    cr_assert(unsorted.putFruit(&lemon) == true);
    cr_assert(unsorted.putFruit(&lemon2) == true);
    cr_assert(unsorted.putFruit(&lime) == true);
    cr_assert(unsorted.putFruit(&lime2) == true);
    cr_assert(unsorted.putFruit(&lime3) == true);
    cr_assert(unsorted.putFruit(&lime4) == true);
    cr_assert(unsorted.putFruit(&banana) == true);
    cr_assert(unsorted.putFruit(&banana2) == true);

    LittleHand::sortFruitBox(unsorted, LemonFruitBox, BananaFruitBox, LimeFruitBox);

    std::cout << "unsorted list:" << std::endl;
    unsorted.printList();
    std::cout << "LemonFruitBox list:" << std::endl;
    LemonFruitBox.printList();
    std::cout << "BananaFruitBox list:" << std::endl;
    BananaFruitBox.printList();
    std::cout << "LimeFruitBox list:" << std::endl;
    LimeFruitBox.printList();
}

Test(Coconut, test_Coconut_class, .init = redirect_all_stdout)
{
    Coconut   coconut;

    cr_assert(coconut.getVitamins() == 15);
    coconut.setVitamins(4);
    cr_assert(coconut.getVitamins() != 15);

    cr_assert(coconut.getName() == "coconut");
    coconut.getName() = "G";
    cr_assert(coconut.getName() != "G");

    coconut.setVitamins(15);
    std::cout << coconut.getVitamins() << std::endl;
    std::cout << coconut.getName() << std::endl;
    cr_assert_stdout_eq_str(
        "15\n"
        "coconut\n");
}

Test(Coconut, test_organizeCoconut_class, .init = redirect_all_stdout)
{
    Coconut *coconut[] = {
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
    FruitBox const* const * coconutBoxes = LittleHand::organizeCoconut(coconut);

    // Print the contents of the coconut boxes
    std::cout << "Organized coconut boxes:" << std::endl;
    int i = 0;
    while (i != 4)
    {
        std::cout << "Box " << i+1 << ": " << coconutBoxes[i]->nbFruit() << std::endl;
        cr_assert(coconutBoxes[i]->nbFruit() == 6);
        i++;
    }
   while (coconutBoxes[i] != nullptr)
    {
        std::cout << "Box " << i+1 << ": " << coconutBoxes[i]->nbFruit() << std::endl;
        cr_assert(coconutBoxes[i]->nbFruit() == 1);
        i++;
    }
    cr_assert(coconutBoxes[i] == nullptr);
}