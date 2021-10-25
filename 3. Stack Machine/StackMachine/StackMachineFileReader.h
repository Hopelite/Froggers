#pragma once
#include <string>
#include "StackMachine.h"
#include <fstream>
#include <vector>
#include <map>

class StackMachineFileReader : public StackMachine
{
public:
	StackMachineFileReader(const std::string& pathToFile);
	~StackMachineFileReader();

	void startReading();

private:
	std::map<std::string, std::vector<std::string>>* functions;

	void parseFunction(std::string functionName);

	// Outer function
	void print();
};

