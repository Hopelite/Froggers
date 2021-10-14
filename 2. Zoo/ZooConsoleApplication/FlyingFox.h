#pragma once
#include "Fox.h"
#include "Bat.h"

class FlyingFox final : protected Bat, private Fox
{
public:
	FlyingFox();
	FlyingFox(short age);
	FlyingFox(std::string name);
	FlyingFox(std::string name, short age);
	FlyingFox(std::string name, short age, std::string location);

	std::string move() override;
	std::string makeSound() override;
	short getAge() override;
	void setAge(short age) override;
	std::string getLocation() override;
	void setLocation(std::string) override;
	void feed(short eat) override;
	short getNumberOfMeals() override;
};