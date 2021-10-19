#include "Racoon.h"

Racoon::Racoon()
{
	Animal::setName("rockie");
	Methods::feed(0);
	Methods::setAge(0);
	Methods::setLocation("");
}

std::string Racoon::makeSound()
{
	return "khaaaah-khuuuu";
}

std::string Racoon::move()
{
	if (Methods::getNumberOfMeals() >= 0 && Methods::getNumberOfMeals() <= 10) {
		return "I'm climbing";
	}
	else if (Methods::getNumberOfMeals() <= 0) {
		return "I'm dying";
	}
	else {
		return "I'm stuck in the hollow";
	}
}