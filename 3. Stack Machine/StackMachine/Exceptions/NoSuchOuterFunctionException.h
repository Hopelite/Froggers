#pragma once
#include <string>
#include <exception>

class NoSuchOuterFunctionException : public std::exception
{
public:
	NoSuchOuterFunctionException(std::string functionName) : message("Can't find outer function \"" + functionName + "\".\n") {}

	virtual ~NoSuchOuterFunctionException() noexcept {}

	const char* what() const noexcept
	{
		return this->message.c_str();
	}

private:
	const std::string message;
};