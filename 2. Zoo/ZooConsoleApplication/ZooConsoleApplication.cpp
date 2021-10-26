#include <iostream>
#include "Animal.h"
#include "Beaver.h"
#include "Duck.h"
#include "Platypus.h"
#include "FlyingFox.h"
#include "Racoon.h"
#include "Bassariscus.h"
#include "Cat.h"
#include "Dog.h"
#include "Bat.h"
#include "Fox.h"
#include "CatDog.h"
#include "Valchnep.h"

int main()
{
	Animal* animal;
	Racoon racoon;
	Cat cat;
	Bassariscus bas;
	Dog dog;
	CatDog catdog;
	Duck duck;
	Beaver beaver;
	Bat bat;
	Fox fox;
	FlyingFox flyingFox;
	Platypus perry;
	Valchnep valchnep;

	//animal = &racoon;
	//animal = &cat;
	//animal = &bas;
	//animal = &dog;
	//animal = &catdog;
	//animal = &duck;
	//animal = &beaver;
	//animal = &perry;
	//animal = &bat;
	//animal = &fox;
	//animal = &flyingFox;
	animal = &valchnep;

	std::cout << animal->makeSound() << std::endl;
	std::cout << animal->move() << std::endl;
	
}