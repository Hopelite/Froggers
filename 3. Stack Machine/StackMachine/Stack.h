#pragma once
#include "StackElement.h"

class Stack
{
public:
	Stack();
	~Stack();

	int getCount();

	void push(int value);
	int pop();
	int peek();
	void duplicate();

private:
	int count;
	StackElement* top;
};

