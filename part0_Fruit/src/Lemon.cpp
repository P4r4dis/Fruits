#include "../include/Lemon.hpp"

Lemon::Lemon(void) :    _name("lemon"),
                        _vitamins(3)
{}

Lemon::~Lemon(void)
{}

std::string             Lemon::getName(void) const
{
    return _name;
}

int                     Lemon::getVitamins(void) const
{
    return _vitamins;
}

void                    Lemon::setVitamins(int vitamins)
{
    _vitamins = vitamins;
}