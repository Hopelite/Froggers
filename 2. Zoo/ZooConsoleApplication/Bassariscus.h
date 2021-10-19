#pragma once
#include <iostream>
#include "Cat.h"
#include "Racoon.h"

class Bassariscus : public Cat, public Racoon
{
public:
	Bassariscus();
	std::string move() override;
	std::string makeSound() override;
};