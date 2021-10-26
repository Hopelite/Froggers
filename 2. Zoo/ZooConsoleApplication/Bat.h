#pragma once
#include <iostream>
#include "Animal.h"
#include "Methods.h"

class Bat : public virtual Animal, public virtual Methods
{
public:
	Bat();
	Bat(short age);
	Bat(std::string name);
	Bat(std::string name, short age);
	Bat(std::string name, short age, std::string location);

	std::string makeSound() override;
	std::string move() override;
};