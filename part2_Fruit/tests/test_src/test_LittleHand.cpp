#include "../test_include/test_LittleHand.hpp"

void                    LittleHand::sortFruitBox(FruitBox &unsorted,
                                                FruitBox &lemons,
                                                FruitBox &bananas,
                                                FruitBox &limes)
{
    FruitNode* current = unsorted.head();
    
    if (current == nullptr)
        return;
    
    while (current != nullptr)
    {
        Fruit* fruit = current->fruit;    
        bool added = false;

        if (fruit->getName() == "lemon") {
            added = lemons.putFruit(fruit);
            unsorted.pickFruit();
        }
        else if (fruit->getName() == "banana")
        {
            added = bananas.putFruit(fruit);
            unsorted.pickFruit();
        }
        else if (fruit->getName() == "lime"){
            added = limes.putFruit(fruit);
            unsorted.pickFruit();
        }
        if (!added)
            unsorted.putFruit(fruit);
        current = current->next;
    }
    return;
}

FruitBox * const        *LittleHand::organizeCoconut(Coconut const * const *coconut)
{
    int     nbCoconut = 0;
    int     nbBox = 0;
    int     coconutByBox = 6;

    // Determine the number of Coconuts needed
    while (coconut[nbCoconut] != nullptr)
        ++nbCoconut;

    // Determine the number of FruitBoxes needed
    nbBox = nbCoconut / coconutByBox;
    while ((nbBox * coconutByBox) < nbCoconut)
        ++nbBox;

    // Allocate an array of FruitBoxes
    FruitBox **cocoBox = new FruitBox*[nbBox + 1];
    for(int i = 0; i < nbBox; i++)
        cocoBox[i] = new FruitBox(coconutByBox);
        
    // Null-terminate the array
    cocoBox[nbBox] = nullptr;

    // Fill the FruitBoxes with Coconuts
    int cocoBoxIndex = 0;
    for (int i = 0; i < nbCoconut; ++i)
    {
        if (!cocoBox[cocoBoxIndex]->putFruit((Coconut *) coconut[i]))
        {
            ++cocoBoxIndex;
            cocoBox[cocoBoxIndex]->putFruit((Coconut *) coconut[i]);
        }
    }

    return cocoBox;
}
