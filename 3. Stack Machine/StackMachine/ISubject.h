#pragma once
#include "IObserver.h"
#include <string>

class ISubject
{
public:
	virtual ~ISubject() {};
	virtual void attach(IObserver* observer) = 0;
	virtual void detach() = 0;

protected:
	virtual void notify(const std::string& message) = 0;
};
