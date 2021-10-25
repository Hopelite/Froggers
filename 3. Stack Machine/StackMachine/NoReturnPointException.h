#pragma once
#include <exception>
#include <string>

class NoReturnPointException : public std::exception
{
public:
	NoReturnPointException(std::string functionName) : message("Function \"" + functionName + "\" has no \"return\" operator.\n") {}

	virtual ~NoReturnPointException() noexcept {}

	const char* what() const noexcept
	{
		return this->message.c_str();
	}

private:
	const std::string message;
};
