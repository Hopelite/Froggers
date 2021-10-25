#pragma once
#include <string>
#include "ISubject.h"

class ConsoleLogger : public IObserver
{
public:
	// Logger recieves subject to observe.
	ConsoleLogger(ISubject* subject);

	// Method that is calling by the subject when changes occur.
	void update(const std::string& message) override;
};

