#include "pch.h"
#include "StackMachine.h"
#include "NotEnoughOperandsException.h"
#include "DivisionByZeroException.h"

void StackMachine::add()
{
	this->checkNumberOfOperands();

	int rhs = this->pop(), lhs = this->pop();
	this->notify("Add " + std::to_string(lhs) + " to " + std::to_string(rhs) + ".\n");
	this->push(lhs + rhs);
}

void StackMachine::subtract()
{
	this->checkNumberOfOperands();

	int rhs = this->pop(), lhs = this->pop();
	this->notify("Subtract " + std::to_string(rhs) + " from " + std::to_string(lhs) + ".\n");
	this->push(lhs - rhs);
}

void StackMachine::multiply()
{
	this->checkNumberOfOperands();

	int rhs = this->pop(), lhs = this->pop();
	this->notify("Multiply " + std::to_string(lhs) + " on " + std::to_string(rhs) + ".\n");
	this->push(lhs * rhs);
}

void StackMachine::divide()
{
	this->checkNumberOfOperands();

	int rhs = this->pop(), lhs = this->pop();
	if (rhs == 0)
	{
		this->notify("Thrown exception: DivisionByZeroException.\n");
		throw DivisionByZeroException();
	}
	else
	{
		this->notify("Divide " + std::to_string(lhs) + " on " + std::to_string(rhs) + ".\n");
		this->push(lhs / rhs);
	}
}

// Check whether number of operands equals or greater than 2.
void StackMachine::checkNumberOfOperands()
{
	if (this->getCount() < 2)
	{
		this->notify("Thrown exception: NotEnoughOperandsException. Number of operands in stack: " + std::to_string(this->getCount()) + ".\n");
		throw NotEnoughOperandsException();
	}
}
