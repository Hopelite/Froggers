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

	void startParsing();
	// Adds outer function, written on C++ with it's name, by which it's called in file.
	void addOuterFunction(std::string functionName, std::function<void(Stack*)> function);

private:
	std::map<std::string, std::vector<std::string>>* functions;
	std::map<std::string, std::function<void(Stack*)>>* outerFunctions;

	void parseFunction(std::string functionName);
	void findLabel(std::vector<std::string>& functionBody, std::string label, int &index);

	void openAndReadFile(const std::string& pathToFile);
	void readFile(std::ifstream& fileStream);
	void readFunction(std::ifstream& fileStream, std::string& fileString);
	void skipComment(std::ifstream& fileStream, std::string& currentString);
	void readTill(std::string symbol, std::ifstream& fileStream, std::string& currentString, std::vector<std::string>& functionBody);
};

