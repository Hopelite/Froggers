#pragma once
#include <exception>
#include <string>

class NoSuchElementException : public std::exception
{
public:
	NoSuchElementException() : message("Can't find a vertex.\n") {}

	virtual ~NoSuchElementException() noexcept {}

	const char* what() const noexcept
	{
		return this->message.c_str();
	}

private:
	const std::string message;
};