#ifndef                 __TEST_LITTLEHAND__
    #define             __TEST_LITTLEHAND__
#include "test_FruitBox.hpp"

class                   LittleHand
{
    public:
        LittleHand(void) {};
        ~LittleHand(void) {};
        static void     sortFruitBox(   FruitBox &unsorted,
                                        FruitBox &lemon,
                                        FruitBox &banana,
                                        FruitBox &lime);
};
#endif //               !__TEST_LITTLEHAND
