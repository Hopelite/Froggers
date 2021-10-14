#pragma once
#include "Beaver.h"
#include "Duck.h"

class Platypus : public Beaver, public Duck
{
public:
	virtual std::string makeSound() override;
	virtual int getNumberOfWings() override;
	virtual std::string move() override;
};

