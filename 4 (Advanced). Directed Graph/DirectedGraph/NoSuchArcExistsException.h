#pragma once
#include <exception>
#include <string>

class NoSuchArcExistsException : public std::exception
{
public:
	NoSuchArcExistsException() : message("Can't find arc.\n") {}

	virtual ~NoSuchArcExistsException() noexcept {}

	const char* what() const noexcept
	{
		return this->message.c_str();
	}

private:
	const std::string message;
};