#pragma once
#include <exception>
#include <string>

class ArcAlreadyExistsException : public std::exception
{
public:
	ArcAlreadyExistsException() : message("Arc already exists.\n") {}

	virtual ~ArcAlreadyExistsException() noexcept {}

	const char* what() const noexcept
	{
		return this->message.c_str();
	}

private:
	const std::string message;
};