#pragma once
#include <string>
#include "..\StackMachine\ISubject.h"

class ConsoleLogger : public IObserver
{
public:
	ConsoleLogger(ISubject* subject);

	void update(const std::string& message) override;
};

