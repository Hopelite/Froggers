#include <iostream>
#include "Animal.h"
#include "Beaver.h"
#include "Duck.h"
#include "Platypus.h"

int main()
{
	Animal* animal;
	Platypus perry;

	animal = &perry;
	std::cout << animal->makeSound() << std::endl;
	std::cout << animal->move() << std::endl;
}