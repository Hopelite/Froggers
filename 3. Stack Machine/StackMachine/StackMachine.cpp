#include "pch.h"
#include "StackMachine.h"
#include "NotEnoughOperandsException.h"
#include "DevisionByZeroException.h"

void StackMachine::add()
{
	this->checkNumberOfOperands();

	int rhs = this->pop(), lhs = this->pop();
	this->push(lhs + rhs);
}

void StackMachine::subtract()
{
	this->checkNumberOfOperands();

	int rhs = this->pop(), lhs = this->pop();
	this->push(lsh - rsh);
}

void StackMachine::multiply()
{
	this->checkNumberOfOperands();

	int rhs = this->pop(), lhs = this->pop();
	this->push(lhs * rhs);
}

void StackMachine::divide()
{
	this->checkNumberOfOperands();

	int rhs = this->pop(), lhs = this->pop();
	if (rhs == 0)
	{
		throw DevisionByZeroException();
	}
	else
	{
		this->push(lhs / rhs);
	}

}

// Check whether number of operands equals or greater than 2.
void StackMachine::checkNumberOfOperands()
{
	if (this->getCount() < 2)
	{
		throw NotEnoughOperandsException();
	}
}
