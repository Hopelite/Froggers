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
	while (this->top != nullptr)
	{
		StackElement* elementToDelete = this->top;
		this->top = this->top->getNext();
		delete elementToDelete;
	}
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
	int value;
	if (this->top != nullptr)
	{
		value = this->top->getValue();
		StackElement* tmp = this->top;
		tmp = tmp->getNext();
		delete this->top;
		this->top = tmp;
	}
	else
	{
		throw StackIsEmptyException();
	}

	this->count--;
	return value;
}

int Stack::peek()
{
	if (this->count == 0)
	{
		throw StackIsEmptyException();
	}

	return this->top->getValue();
}

void Stack::duplicate()
{
	if (this->count == 0)
	{
		throw StackIsEmptyException();
	}

	this->push(this->top->getValue());
}