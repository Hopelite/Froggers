#pragma once
#include <string>
#include "StackMachine.h"
#include <fstream>
#include "NoSuchFileException.h"

class StackMachineFileReader : public StackMachine
{
public:
	StackMachineFileReader(const std::string& pathToFile);

	void startReading();

	std::string getPathToFile()
	{
		return pathToFile;
	}

private:
	std::string pathToFile;
};

