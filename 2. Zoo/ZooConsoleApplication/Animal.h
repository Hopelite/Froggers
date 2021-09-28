#pragma once
#include <iostream>

class Animal
{
public:
	virtual std::string makeSound() = 0;
	virtual std::string getSex() = 0;
	virtual void setSex() = 0;

	virtual int getNumberOfLegs() = 0;
	virtual void setNumberOfLegs() = 0;

private:
	std::string sex;
	int numberOfLegs;
};

