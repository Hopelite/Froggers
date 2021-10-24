#pragma once
#include <exception>

class NoSuchFileException : public std::exception
{
public:
	NoSuchFileException() : message("No such file or directory.\n") {}

	virtual ~NoSuchFileException() noexcept {}

	const char* what() const noexcept
	{
		return this->message;
	}

private:
	const char* message;
};