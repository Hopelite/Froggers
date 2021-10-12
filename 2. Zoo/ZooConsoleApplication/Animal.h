#pragma once
#include <iostream>

class Animal
{
public:
	virtual std::string makeSound() = 0;
	virtual std::string move() = 0;

	virtual void setName(std::string name)
	{
		this->name = name;
	}

	virtual std::string getName()
	{
		return this->name;
	}

private:
	std::string name;
};