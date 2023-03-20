#ifndef                 __FRUITNODE__
    #define             __FRUITNODE__
#include "Fruit.hpp"

struct                  FruitNode
{
        FruitNode(Fruit *f) : fruit(f), next(nullptr) {}
        ~FruitNode() { delete next; }
        
        Fruit           *fruit;
        FruitNode       *next;
};


#endif //               !__FRUITNODE__