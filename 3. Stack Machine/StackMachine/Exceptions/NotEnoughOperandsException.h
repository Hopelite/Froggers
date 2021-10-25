#pragma once
#include <exception>

class NotEnoughOperandsException : public std::exception
{
public:
	NotEnoughOperandsException() : message("Not enought operands in stack for evaluation.\n") {}

	virtual ~NotEnoughOperandsException() noexcept {}

	const char* what() const noexcept
	{
		return this->message;
	}

private:
	const char* message;
};

