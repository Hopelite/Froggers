#pragma once
#include <exception>
#include <string>

class NoSuchLabelException : public std::exception
{
public:
	NoSuchLabelException(std::string labelName) : message("Can't find label \"" + labelName + "\".\n") {}

	virtual ~NoSuchLabelException() noexcept {}

	const char* what() const noexcept
	{
		return this->message.c_str();
	}

private:
	const std::string message;
};