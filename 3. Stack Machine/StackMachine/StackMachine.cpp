#include "pch.h"
#include "StackMachine.h"
#include "NotEnoughOperandsException.h"

void StackMachine::add()
{
	this->checkNumberOfOperands();

	int rhs = this->pop(), lhs = this->pop();
	this->push(lhs + rhs);
}

void StackMachine::subtract()
{
	//TODO: Implement subtract() method.
}

void StackMachine::multiply()
{
	this->checkNumberOfOperands();

	int rhs = this->pop(), lhs = this->pop();
	this->push(lhs * rhs);
}

void StackMachine::divide()
{
	//TODO: Implement divide() method.
}

// Check whether number of operands equals or greater than 2.
void StackMachine::checkNumberOfOperands()
{
	if (this->getCount() < 2)
	{
		throw NotEnoughOperandsException();
	}
}
