#include "pch.h"
#include "framework.h"
#include "Stack.h"
#include "Exceptions/StackIsEmptyException.h"

Stack::Stack()
{
	this->top = nullptr;
	this->count = 0;
	this->observer = nullptr;
}

// Destructor deletes all elements in stack step by step.
Stack::~Stack()
{
	while (this->top != nullptr)
	{this->pop();
	}

	this->detach();
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
	this->notify("Push " + std::to_string(value) + " to stack.\n");
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
		this->notify("Thrown exception: StackIsEmptyException.\n");
		throw StackIsEmptyException();
	}

	this->count--;
	this->notify("Pop " + std::to_string(value) + " from stack.\n");
	return value;
}

int Stack::peek()
{
	if (this->count == 0)
	{
		throw StackIsEmptyException();
	}

	this->notify("Peek " + std::to_string(this->top->getValue()) + " from stack.\n");
	return this->top->getValue();
}

void Stack::duplicate()
{
	if (this->count == 0)
	{
		this->notify("Thrown exception: StackIsEmptyException.\n");
		throw StackIsEmptyException();
	}

	this->notify("Duplicate " + std::to_string(this->top->getValue()) + " in stack.\n");
	this->push(this->top->getValue());
}

void Stack::attach(IObserver* observer)
{
	this->observer = observer;
}

void Stack::detach()
{
	this->observer = nullptr;
}

void Stack::notify(const std::string& message)
{
	if (this->observer != nullptr)
	{
		this->observer->update(message);
	}
}
