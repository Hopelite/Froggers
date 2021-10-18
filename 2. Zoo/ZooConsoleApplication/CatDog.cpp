#include "CatDog.h"


std::string CatDog::makeSound()
{
    return Dog::makeSound() + " end " + Cat::makeSound();
}

std::string CatDog::move()
{
    return "Not to move, only to sleep.";
}
