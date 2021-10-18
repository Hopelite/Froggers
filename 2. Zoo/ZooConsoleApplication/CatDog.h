#pragma once
#include "Cat.h"
#include "Dog.h"

class CatDog : public Cat, public Dog 
{
public:
	virtual std::string makeSound() override;
	virtual std::string move() override;
};

