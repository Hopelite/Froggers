#pragma once
#include <exception>

class StackIsEmptyException : public std::exception
{
public:
	StackIsEmptyException() : message("Stack is empty.\n") {}

	virtual ~StackIsEmptyException() noexcept {}

	const char* what() const noexcept
	{
		return this->message;
	}

private:
	const char* message;
};

