#include "FlyingFox.h"
#include <iostream>

FlyingFox::FlyingFox()
{
	Methods::feed(0);
	Methods::setAge(0);
	Methods::setLocation("");
}

FlyingFox::FlyingFox(short age) : FlyingFox()
{
	Methods::setAge(age);
}

FlyingFox::FlyingFox(std::string name) : FlyingFox()
{
	Animal::setName(name);
}

FlyingFox::FlyingFox(std::string name, short age) : FlyingFox(age)
{
	Animal::setName(name);
}

FlyingFox::FlyingFox(std::string name, short age, std::string location) : FlyingFox(name, age)
{
	Methods::setLocation(location);
}

std::string FlyingFox::move()
{
	return Fox::move() + " and " + Bat::move();
}

std::string FlyingFox::makeSound()
{
	return Bat::makeSound();
}

std::string FlyingFox::getName()
{
	return Animal::getName();
}

void FlyingFox::setName(std::string name)
{
	return Animal::setName(name);
}

short FlyingFox::getAge()
{
	return Methods::getAge();
}
void FlyingFox::setAge(short age)
{
	Methods::setAge(age);
}

std::string FlyingFox::getLocation()
{
	return Methods::getLocation();
}

void FlyingFox::setLocation(std::string location)
{
	Methods::setLocation(location);
}

void FlyingFox::feed(short eat)
{
	Bat::feed(eat);
}

short FlyingFox::getNumberOfMeals()
{
	return Bat::getNumberOfMeals();
}