#pragma once
#include <exception>
#include <string>

class NoSuchFunctionException : public std::exception
{
public:
	NoSuchFunctionException(std::string functionName) : message("Can't find function \"" + functionName + "\".\n") {}

	virtual ~NoSuchFunctionException() noexcept {}

	const char* what() const noexcept
	{
		return this->message.c_str();
	}

private:
	const std::string message;
};

