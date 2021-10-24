#pragma once
#include <string>
#include "StackMachine.h"

class StackMachineFileReader : public StackMachine
{
public:
	StackMachineFileReader(const std::string& pathToFile);

	void startReading();

private:
	std::string pathToFile;
};

