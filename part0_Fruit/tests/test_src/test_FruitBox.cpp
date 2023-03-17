#include "../test_include/test_FruitBox.hpp"

FruitBox::FruitBox(const int size) :    m_size(size),
                                        m_nbFruit(0),
                                        m_head(nullptr)
{}

FruitBox::~FruitBox(void)
{}

int                     FruitBox::getSize(void) const
{
    return m_size;
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