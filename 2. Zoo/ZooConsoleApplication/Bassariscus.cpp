#include "Bassariscus.h"

Bassariscus::Bassariscus()
{
	Animal::setName("bassie");
	Methods::feed(0);
	Methods::setAge(0);
	Methods::setLocation("");
}

std::string Bassariscus::makeSound()
{
	return "k-chee-uuuuu";
}

std::string Bassariscus::move()
{
	return Racoon::move();
}