#pragma once
#include "Stack.h"

class StackMachine : public Stack
{
public:
	void add();
	void subtract();
	void multiply();
	void divide();

private:
	void checkNumberOfOperands();
};
