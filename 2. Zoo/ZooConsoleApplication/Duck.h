#pragma once
#include "Animal.h"

class Duck : public virtual Animal
{
public:
    virtual std::string makeSound() override;
    virtual std::string move() override;
    virtual int getNumberOfWings();
};

