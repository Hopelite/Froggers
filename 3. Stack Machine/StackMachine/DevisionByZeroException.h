#pragma once
#include <exception>

class DevisionByZeroException : public std::exception
{
public:
	DevisionByZeroException() : message("Division by zero.\n") {}

	virtual ~DevisionByZeroException() noexcept {}

	const char* what() const noexcept
	{
		return this->message;
	}

private:
	const char* message;
};