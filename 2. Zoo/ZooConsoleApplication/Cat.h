#pragma once
#include "Animal.h"
#include "Methods.h"

class Cat : public virtual Animal, public virtual Methods
{
public:
	Cat();
	virtual std::string makeSound() override;
	virtual std::string move() override;
};
