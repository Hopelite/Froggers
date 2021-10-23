#pragma once
class StackElement
{
public:
	StackElement(int value, StackElement* next)
	{
		this->value = value;
		this->next = next;
	}

private:
	int value;
	StackElement* next;
};

