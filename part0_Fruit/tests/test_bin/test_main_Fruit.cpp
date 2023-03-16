#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_Fruit.hpp"
#include "../test_include/test_Lemon.hpp"
#include "../test_include/test_Banana.hpp"


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