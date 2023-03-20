#ifndef                 __TEST_FRUITNODE__
    #define             __TEST_FRUITNODE__
#include "test_Fruit.hpp"

struct                  FruitNode
{
        FruitNode(Fruit *f) : fruit(f), next(nullptr) {}
        ~FruitNode() { delete next; }
        
        Fruit           *fruit;
        FruitNode       *next;
};


#endif //               !__TEST_FRUITNODE__