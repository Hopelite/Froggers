#pragma once
#include <exception>
#include <string>

template<typename T>
class ArcAlreadyExistsException : public std::exception
{
public:
	ArcAlreadyExistsException(const T& start, const T& end) : message("Arc  \"" + start + " - " + end + "\" already exists.\n") {}

	virtual ~ArcAlreadyExistsException() noexcept {}

	const char* what() const noexcept
	{
		return this->message.c_str();
	}

private:
	const std::string message;
};