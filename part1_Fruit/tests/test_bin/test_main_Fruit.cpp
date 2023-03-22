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

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Lemon, test_Lemon_class, .init = redirect_all_stdout)//, .signal = SIGPIPE, .init = redirect_all_stdout)
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

Test(Banana, test_Banana_class, .init = redirect_all_stdout)//, .signal = SIGPIPE, .init = redirect_all_stdout)
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

Test(Fruit, test_Fruit_class, .init = redirect_all_stdout)//, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Lemon   l;
    Fruit &f = l;

    std::cout << f.getVitamins() << std::endl;
    std::cout << f.getName() << std::endl;
    cr_assert_stdout_eq_str(
        "3\n"
        "lemon\n");
}

Test(FruitBox, test_FruitBox_class, .init = redirect_all_stdout)//, .signal = SIGPIPE, .init = redirect_all_stdout)
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

Test(FruitBox, test_FruitBox_putFruit, .init = redirect_all_stdout)//, .signal = SIGSEGV, .init = redirect_all_stdout)//, .signal = SIGPIPE, .init = redirect_all_stdout)
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

// fbox.display();
    // fbox.~FruitBox();
    // cr_assert_stdout_eq_str(
    //     "3\n"
    //     "5\n"
    //     "lemon\n"
    //     "banana\n"
    //     "3\n"
    //     "lemon\n");
}


Test(FruitBox, test_FruitBox_pickFruit, .init = redirect_all_stdout)//, .signal = SIGSEGV)//)//, .signal = SIGPIPE, .init = redirect_all_stdout)
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

    fbox.putFruit(&l);
    fbox.putFruit(&b);

    fbox.pickFruit();
    cr_assert(fbox.head()->fruit == &b);
    // std::cout << "Fruit in the Box : " << std::endl;

    // while (fbox.head() != nullptr)
    // {
    //     std::cout << fbox.head()->fruit->getName() << std::endl;
    //     fbox.setHead(fbox.head()->next);
    // }

// fbox.display();
    // fbox.~FruitBox();
    // cr_assert_stdout_eq_str(
    //     "3\n"
    //     "5\n"
    //     "lemon\n"
    //     "banana\n"
    //     "3\n"
    //     "lemon\n");
}

Test(Lime, test_Lime_class, .init = redirect_all_stdout)//, .signal = SIGPIPE, .init = redirect_all_stdout)
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

Test(LittleHand, test_LittleHand_unsorted, .init = redirect_all_stdout)//, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Lime    lime, lime2, lime3, lime4;
    Lemon   lemon, lemon2;
    Banana  banana, banana2;
    Fruit &f = lime;

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

    unsorted.putFruit(&banana );
    unsorted.putFruit(&banana2);

    unsorted.putFruit(&f);


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
}