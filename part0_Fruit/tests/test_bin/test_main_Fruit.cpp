#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_Fruit.hpp"
#include "../test_include/test_Lemon.hpp"


void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Lemon, test_Lemon_class)//, .signal = SIGPIPE, .init = redirect_all_stdout)
{
    Lemon   l;

    cr_assert(l.getVitamins() == 3);
    l.setVitamins(4);
    cr_assert(l.getVitamins() != 3);

    cr_assert(l.getName() == "lemon");
    l.getName() = "G";
    cr_assert(l.getName() != "G");

}
