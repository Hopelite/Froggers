#include "pch.h"
#include "framework.h"
#include "ConsoleLogger.h"
#include "..\StackMachine\ISubject.h"
#include <iostream>

ConsoleLogger::ConsoleLogger(ISubject* subject)
{
	subject->attach(this);
}

void ConsoleLogger::update(const std::string& message)
{
	std::cout << message;
}
