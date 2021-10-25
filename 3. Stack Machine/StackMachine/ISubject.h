#pragma once
#include "IObserver.h"
#include <string>

// Interface that guarantees implementation of methods for observable type.
class ISubject
{
public:
	virtual ~ISubject() {};
	// Attaches specified observer to current subject.
	virtual void attach(IObserver* observer) = 0;
	// Detaches specified observer from current subject.
	virtual void detach() = 0;

protected:
	// Method that is called to notify all observers, that have subscribed to current subject.
	virtual void notify(const std::string& message) = 0;
};
