#include "Bat.h"
#include <iostream>

Bat::Bat()
{
	Methods::feed(0);
	Methods::setAge(0);
	Methods::setLocation("");
}

Bat::Bat(short age) : Bat()
{
	Methods::setAge(age);
}

Bat::Bat(std::string name) : Bat()
{
	Animal::setName(name);
}

Bat::Bat(std::string name, short age) : Bat(age)
{
	Animal::setName(name);
}

Bat::Bat(std::string name, short age, std::string location) : Bat(name, age)
{
	Methods::setLocation(location);
}

std::string Bat::move()
{
	if (Methods::getNumberOfMeals() >= 0 && Methods::getNumberOfMeals() <= 10) {
		return "I can to fly";
	} else if (Methods::getNumberOfMeals() <= 0) {
		return "I can't fly 'cause I'm a hungry";
	} else {
		return "I can't fly 'cause I'm a fat";
	}
}

std::string Bat::makeSound()
{
	return "Ultrasound!";
}