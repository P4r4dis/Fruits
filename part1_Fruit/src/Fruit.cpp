#include "../include/Fruit.hpp"

Fruit::Fruit(void)
{}

Fruit::~Fruit(void)
{}

std::string             Fruit::getName(void) const
{
    return m_name;
}

int                     Fruit::getVitamins(void) const
{
    return m_vitamins;
}

void                    Fruit::setName(std::string name)
{
    m_name = name;
}

void                    Fruit::setVitamins(int vitamins)
{
    m_vitamins = vitamins;
}