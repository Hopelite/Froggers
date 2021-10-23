#pragma once
#include "StackElement.h"

class StackMachine
{
public:
	StackMachine();
	~StackMachine();

	int getCount();

	void push(int value);
	int pop();
	int peek();
	void duplicate();

private:
	int count;
	StackElement* top;
};

