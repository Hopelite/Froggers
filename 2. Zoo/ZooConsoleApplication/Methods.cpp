#include "Methods.h"

short Methods::getAge()
{
	return this->age;
}
void Methods::setAge(short age)
{
	this->age = age;
}

std::string Methods::getLocation()
{
	return this->location;
}

void Methods::setLocation(std::string location)
{
	this->location = location;
}

void Methods::feed(short eat)
{
	eat ? this->numberOfMeals += eat : this->numberOfMeals -= eat;
}

short Methods::getNumberOfMeals()
{
	return this->numberOfMeals;
}