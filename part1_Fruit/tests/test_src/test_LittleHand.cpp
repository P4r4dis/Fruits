#include "../test_include/test_LittleHand.hpp"

void             LittleHand::sortFruitBox(FruitBox &unsorted,
                                            FruitBox &lemon,
                                            FruitBox &banana,
                                            FruitBox &lime)
{
        FruitNode* current = unsorted.head();
        if (current == nullptr)
            return;
        while (current != nullptr)
        {
            if (current->fruit->getName() == "lemon")
            {
                if (lemon.putFruit(current->fruit))
                    unsorted.pickFruit();
            }
            else if (current->fruit->getName() == "banana")
            {
                if (banana.putFruit(current->fruit))
                    unsorted.pickFruit();
            }
            else if (current->fruit->getName() == "lime")
            {
                if (lime.putFruit(current->fruit))
                    unsorted.pickFruit();
            }
            current = current->next;
        }
}
