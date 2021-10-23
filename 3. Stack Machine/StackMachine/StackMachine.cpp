#include "pch.h"
#include "framework.h"
#include "StackMachine.h"

StackMachine::StackMachine()
{
	this->top = nullptr;
	this->count = 0;
}

StackMachine::~StackMachine()
{
	//TODO: Implement destructor logic.
}

int StackMachine::getCount()
{
	return this->count;
}

void StackMachine::push(int value)
{
	if (this->top == nullptr)
	{
		this->top = new StackElement(value, nullptr);
	}
	else
	{
		this->top = new StackElement(value, this->top);
	}

	this->count++;
}

int StackMachine::pop()
{
	// TODO: Implement Pop() method.
	return 0;
}

int StackMachine::peek()
{
	// TODO: Implement Peek() method.
	return 0;
}

void StackMachine::duplicate()
{
	// TODO: Implement Duplicate() method.
}