#ifndef                 __LITTLEHAND__
    #define             __LITTLEHAND__
#include "FruitBox.hpp"
#include "Coconut.hpp"
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
#endif //               !__LITTLEHAND__