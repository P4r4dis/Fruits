#include "../test_include/test_FruitBox.hpp"

FruitBox::FruitBox(const int size) :    m_size(size),
                                        m_nbFruit(0),
                                        m_head(nullptr)
{}

FruitBox::~FruitBox(void)
{
    delete m_head;
}

int                     FruitBox::getSize(void) const
{
    return m_size;
}

void                    FruitBox::setHead(FruitNode *f)
{
    m_head = f;
}

int                     FruitBox::nbFruit(void) const
{
    return m_nbFruit;
}

FruitNode               *FruitBox::head(void) const
{
    if (m_nbFruit == 0)
        return nullptr;
    return m_head;
}

bool                    FruitBox::putFruit(Fruit *f)
{
    // 1: Check if FruitBox is full
    if(m_nbFruit >= m_size)
        return false;
    
    // 2: Create an currentNode becomes head of list
    FruitNode   *currentFruitNode = m_head; // currently nullptr

    // 3: Check if Fruit is already in the FruitBox, for that:
        // 3.1: traverse the list
        // 3.2: return false if current == f
        // 3.3: assign current to current next
    while(currentFruitNode != nullptr)
    {
        if(currentFruitNode->fruit == f)
            return false;
        currentFruitNode = currentFruitNode->next;
    }
    
    // 4: Create a newNode and allocate FruitNode(Fruit)
    FruitNode   *newFruitNode = new FruitNode(f);

    // 5:   If head FruitBox is empty, set the head to the new FruitNode
    //      Otherwise, append the new FruitNode to the end of the linked list :
    //          5.1: Create tailNode and assign head node;
    //          5.2: traverse tail node
    //          5.3: last node of tail->snext = newNode

    if (m_head == nullptr)
        m_head = newFruitNode;
    else
    {
        FruitNode   *tailFruitNode = m_head;
        while (tailFruitNode->next != nullptr)
            tailFruitNode = tailFruitNode->next;
        tailFruitNode->next = newFruitNode;
    }
    // 7: nb of fruit increment
    m_nbFruit++;

    // 8: return true;
    return true;

}