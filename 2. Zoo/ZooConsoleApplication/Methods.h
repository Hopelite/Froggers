#pragma once
#include <iostream>

class Methods
{
public:
	virtual short getAge();
	virtual void setAge(short age);
	virtual std::string getLocation();
	virtual void setLocation(std::string);
	virtual void feed(short eat);
	virtual short getNumberOfMeals();

private:
	short age = 0;
	short numberOfMeals = 0;
	std::string location = "";
};