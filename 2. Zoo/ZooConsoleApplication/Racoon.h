#pragma once
#include "Animal.h"
#include "Methods.h"

class Racoon : public virtual Animal, public virtual Methods
{
public:
	Racoon();
	std::string move() override;
	std::string makeSound() override;
};