#pragma once
#include "Animal.h"
class Beaver : public virtual Animal
{
public:
	virtual std::string makeSound() override;
	virtual std::string move() override;
};

