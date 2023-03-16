#include "../test_include/test_Banana.hpp"

Banana::Banana(void) :  _name("banana"),
                        _vitamins(5)
{}

Banana::~Banana(void)
{}

std::string             Banana::getName(void) const
{
    return _name;
}

int                     Banana::getVitamins(void) const
{
    return _vitamins;
}

void                    Banana::setVitamins(int vitamins)
{
    _vitamins = vitamins;
}