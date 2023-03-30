#ifndef                 __TEST_LITTLEHAND__
    #define             __TEST_LITTLEHAND__
#include "test_FruitBox.hpp"
#include "test_Coconut.hpp"

class                           LittleHand
{
    public:
        LittleHand(void) {};
        ~LittleHand(void) {};
        static void             sortFruitBox(   FruitBox &unsorted,
                                                FruitBox &lemon,
                                                FruitBox &banana,
                                                FruitBox &lime);
        static FruitBox * const *organizeCoconut(Coconut const * const *coconut);
};
#endif //               !__TEST_LITTLEHAND
