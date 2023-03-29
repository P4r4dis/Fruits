#ifndef                 __LITTLEHAND__
    #define             __LITTLEHAND__
#include "FruitBox.hpp"

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
#endif //               !__LITTLEHAND__