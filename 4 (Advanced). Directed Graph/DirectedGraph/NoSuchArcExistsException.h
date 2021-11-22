#pragma once
#include <exception>
#include <string>

template<typename T>
class NoSuchArcExistsException : public std::exception
{
public:
	NoSuchArcExistsException(const T& start, const T& end) : message("Can't find arc \"" + start + " -- " + end + "\".\n") {}

	virtual ~NoSuchArcExistsException() noexcept {}

	const char* what() const noexcept
	{
		return this->message.c_str();
	}

private:
	const std::string message;
};