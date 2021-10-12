#pragma once
#include <iostream>
#include "Animal.h"
#include "Methods.h"

class Fox : public virtual Animal, public virtual Methods
{
public:
	Fox();
	Fox(short age);
	Fox(std::string name);
	Fox(std::string name, short age);
	Fox(std::string name, short age, std::string location);

	std::string move() override;
	std::string makeSound() override;
};