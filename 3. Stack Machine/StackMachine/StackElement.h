#pragma once
class StackElement
{
public:
	StackElement(int value)
	{
		this->value = value;
		this->next = nullptr;
	}

	StackElement(int value, StackElement* next)
	{
		this->value = value;
		this->next = next;
	}

	int getValue()
	{
		return this->value;
	}

	StackElement* getNext()
	{
		return this->next;
	}

private:
	int value;
	StackElement* next;
};

