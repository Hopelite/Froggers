#pragma once
#include "Animal.h"
#include "Methods.h"

class Racoon : private virtual Animal, public virtual Methods
{
public:
	Racoon();
	std::string move() override;
	std::string makeSound() override;
};