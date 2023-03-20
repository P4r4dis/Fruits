#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_Lemon.hpp"
#include "../test_include/test_Banana.hpp"
#include "../test_include/test_FruitBox.hpp"


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

Test(FruitBox, test_FruitBox_putFruit)//, .signal = SIGSEGV, .init = redirect_all_stdout)//, .signal = SIGPIPE, .init = redirect_all_stdout)
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