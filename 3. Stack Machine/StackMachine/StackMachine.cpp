#include "pch.h"
#include "framework.h"
#include "Stack.h"
#include "StackIsEmptyException.h"

Stack::Stack()
{
	this->top = nullptr;
	this->count = 0;
}

Stack::~Stack()
{
	//TODO: Implement destructor logic.
}

int Stack::getCount()
{
	return this->count;
}

void Stack::push(int value)
{
	if (this->top == nullptr)
	{
		this->top = new StackElement(value);
	}
	else
	{
		this->top = new StackElement(value, this->top);
	}

	this->count++;
}

int Stack::pop()
{
	// TODO: Implement Pop() method.
	return 0;
}

int Stack::peek()
{
	// TODO: Implement Peek() method.
	return 0;
}

void Stack::duplicate()
{
	if (this->count == 0)
	{
		throw StackIsEmptyException();
	}

	this->push(this->top->getValue());
}