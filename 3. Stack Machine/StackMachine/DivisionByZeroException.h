#pragma once
#include <exception>

class DivisionByZeroException : public std::exception
{
public:
	DivisionByZeroException() : message("Division by zero.\n") {}

	virtual ~DivisionByZeroException() noexcept {}

	const char* what() const noexcept
	{
		return this->message;
	}

private:
	const char* message;
};