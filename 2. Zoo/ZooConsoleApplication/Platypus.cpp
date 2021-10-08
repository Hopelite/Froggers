#include "Platypus.h"

std::string Platypus::makeSound()
{
    return Duck::makeSound();
}

int Platypus::getNumberOfWings()
{
    return 0;
}

std::string Platypus::move()
{
    return "Like a ninja.";
}
