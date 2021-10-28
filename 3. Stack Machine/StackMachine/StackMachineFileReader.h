#pragma once
#include <string>
#include <functional>
#include <fstream>
#include <vector>
#include <map>
#include "StackMachine.h"

class StackMachineFileReader : public StackMachine
{
public:
	StackMachineFileReader(const std::string& pathToFile);
	~StackMachineFileReader();

	void startReading();
	// Adds outer function, written on C++ with it's name, by which it's called in file.
	void addOuterFunction(std::string functionName, std::function<void(Stack*)> function);

private:
	std::map<std::string, std::vector<std::string>>* functions;
	std::map<std::string, std::function<void(Stack*)>>* outerFunctions;

	void parseFunction(std::string functionName);
	void findLabel(std::vector<std::string>& functionBody, std::string label, int index);
};

