#include "Cat.h"

Cat::Cat()
{
	Animal::setName("kittie");
	Methods::feed(0);
	Methods::setAge(0);
	Methods::setLocation("");
}

std::string Cat::makeSound()
{
	if (Methods::getNumberOfMeals() >= 0 && Methods::getNumberOfMeals() <= 10) {
		return "happy meow-meow";
	}
	else if (Methods::getNumberOfMeals() <= 0) {
		return "hungry meow-meow";
	}
	else {
		return "fat meow-meow";
	}
}

std::string Cat::move()
{
	return "Cat runs.";
}