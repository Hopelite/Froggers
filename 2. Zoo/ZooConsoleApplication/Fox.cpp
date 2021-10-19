#include "Fox.h"
#include <iostream>

Fox::Fox()
{
	Methods::feed(0);
	Methods::setAge(0);
	Methods::setLocation("");
}

Fox::Fox(short age) : Fox()
{
	Methods::setAge(age);
}

Fox::Fox(std::string name) : Fox()
{
	Animal::setName(name);
}

Fox::Fox(std::string name, short age) : Fox(age)
{
	Animal::setName(name);
}

Fox::Fox(std::string name, short age, std::string location) : Fox(name, age)
{
	Methods::setLocation(location);
}

std::string Fox::move()
{
	if (Methods::getNumberOfMeals() >= 0 && Methods::getNumberOfMeals() <= 10) {
		return "I can run";
	} else if (Methods::getNumberOfMeals() <= 0) {
		return "I can't run 'cause I'm hungry";
	} else {
		return "I can't run 'cause I'm fat";
	}
}

std::string Fox::makeSound()
{
	return "Have you given me a name yet?";
}