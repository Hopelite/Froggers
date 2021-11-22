#pragma once
#include <exception>
#include <string>

template<typename T>
class NoSuchElementExeption : public std::exception
{
public:
	NoSuchElementExeption(T vertex) : message("Can't find a vertex \"" + vertex + "\".\n") {}

	virtual ~NoSuchElementExeption() noexcept {}

	const char* what() const noexcept
	{
		return this->message.c_str();
	}

private:
	const std::string message;
};