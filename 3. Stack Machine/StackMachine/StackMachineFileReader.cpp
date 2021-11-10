#include "pch.h"
#include "StackMachineFileReader.h"
#include "Exceptions/NoReturnPointException.h"
#include "Exceptions/NoSuchFileException.h"
#include "Exceptions/NoSuchFunctionException.h"
#include "Exceptions/NoSuchLabelException.h"
#include "Exceptions/NoSuchOuterFunctionException.h"
#include <iostream>
#include <map>

StackMachineFileReader::StackMachineFileReader(const std::string& pathToFile)
{
	this->functions = new std::map<std::string, std::vector<std::string>>;
	this->outerFunctions = new std::map<std::string, std::function<void(Stack*)>>;
	this->openAndReadFile(pathToFile);
}

StackMachineFileReader::~StackMachineFileReader()
{
	delete this->functions;
	delete this->outerFunctions;
}

void StackMachineFileReader::startParsing()
{
	// Start from 'main' function.
	this->parseFunction("main");
}

void StackMachineFileReader::addOuterFunction(std::string functionName, std::function<void(Stack*)> function)
{
	this->outerFunctions->insert(std::pair<std::string, std::function<void(Stack*)>>(functionName, function));
}

void StackMachineFileReader::parseFunction(std::string functionName)
{
	// If specified function doesn't exist throw an exception.
	if (this->functions->find(functionName) == this->functions->end())
	{
		this->notify("Thrown exception: NoSuchFunctionException. Can't find function \"" + functionName + "\".\n");
		throw NoSuchFunctionException(functionName);
	}

	this->notify("Call function \"" + functionName + "\".\n");
	std::vector<std::string> functionBody = this->functions->find(functionName)->second;
	for (int i = 0; i < functionBody.size(); i++)
	{
		if (functionBody[i] == "push")
		{
			int number = std::stoi(functionBody[++i]);
			this->push(number);
		}
		else if (functionBody[i] == "pop")
		{
			this->pop();
		}
		else if (functionBody[i] == "peek")
		{
			this->peek();
		}
		else if (functionBody[i] == "dup")
		{
			this->duplicate();
		}
		else if (functionBody[i] == "add")
		{
			this->add();
		}
		else if (functionBody[i] == "sub")
		{
			this->subtract();
		}
		else if (functionBody[i] == "mul")
		{
			this->multiply();
		}
		else if (functionBody[i] == "div")
		{
			this->divide();
		}
		else if (functionBody[i] == "call")
		{
			this->parseFunction(functionBody[++i]);
		}
		else if (functionBody[i] == "ifeq")
		{
			int rhs = this->pop(), lhs = this->pop();

			this->notify("Compare number " + std::to_string(lhs) + " to number " + std::to_string(rhs) + ".\n");
			if (lhs == rhs)
			{
				this->notify("Numbers are equal.\n");
				this->findLabel(functionBody, functionBody[++i], i);
			}
		}
		else if (functionBody[i] == "goto")
		{
			this->findLabel(functionBody, functionBody[++i], i);
		}
		else if (functionBody[i] == "ifgr")
		{
			int lhs = this->pop(), rhs = this->pop();

			this->notify("Compare number " + std::to_string(lhs) + " to number " + std::to_string(rhs) + ".\n");
			if (lhs > rhs)
			{
				this->notify("Number " + std::to_string(lhs) + "is greater than " + std::to_string(rhs) + ".\n");
				this->findLabel(functionBody, functionBody[++i], i);
			}
		}
		else if (functionBody[i] == "return")
		{
			this->notify("Return from function \"" + functionName + "\".\n");
			return;
		}
		else if (functionBody[i] == "callext")
		{
			this->notify("Searching outer function \"" + functionBody[++i] + "\".\n");
			if (this->outerFunctions->find(functionBody[i]) == this->outerFunctions->end())
			{
				this->notify("Thrown exception: NoSuchOuterFunctionException. Can't find outer function \"" + functionBody[i] + "\".\n");
				throw NoSuchOuterFunctionException(functionBody[i]);
			}

			this->notify("Call outer function \"" + functionBody[i] + "\".\n");
			std::function<void(Stack*)> outerFunction = this->outerFunctions->find(functionBody[i])->second;
			outerFunction(this);
		}
	}

	// If there is no "return" operator in function, throw an exception.
	this->notify("Thrown exception: NoReturnPointException. Function \"" + functionName + "\" has no \"return\" operator.\n");
	throw NoReturnPointException(functionName);
}

void StackMachineFileReader::findLabel(std::vector<std::string>& functionBody, std::string labelName, int& index)
{
	this->notify("Searching label \"" + labelName + "\".\n");
	std::string label = labelName + ":";

	// Search specified label in the code below.
	while (index < functionBody.size() && functionBody[index] != label)
	{
		index++;
	}

	if (index == functionBody.size())
	{
		this->notify("Thrown exception: NoSuchLabelException. Can't find label \"" + labelName + "\".\n");
		throw NoSuchLabelException(labelName);
	}

	this->notify("Moving to label \"" + labelName + "\".\n");
}

void StackMachineFileReader::openAndReadFile(const std::string& pathToFile)
{
	// Opens file and starts reading it's content.
	std::ifstream fileStream(pathToFile);
	if (!fileStream.is_open())
	{
		this->notify("Thrown exception: NoSuchFileException. No such file or directory.\n");
		throw NoSuchFileException();
	}
	else
	{
		this->readFile(fileStream);
	}

	fileStream.close();
}

void StackMachineFileReader::readFile(std::ifstream& fileStream)
{
	std::string fileString;
	// While didn't reach end of file.
	while (!fileStream.eof())
	{
		fileStream >> fileString;
		// If string is beginning of function...
		if (fileString == "function")
		{
			this->readFunction(fileStream, fileString);
		}
	}
}

void StackMachineFileReader::readFunction(std::ifstream& fileStream, std::string& fileString)
{
	const std::string beginningOfFunction = "{", endOfFunction = "}";

	fileStream >> fileString;
	std::string currentString;
	std::vector<std::string> functionBody;
	fileStream >> currentString;
	// Skipping comments and other non-function content.
	while (currentString != beginningOfFunction && !fileStream.eof())
	{
		fileStream >> currentString;
	}

	fileStream >> currentString;

	this->readTill(endOfFunction, fileStream, currentString, functionBody);

	// Add function body to dictionary, where key is the function's name.
	this->functions->insert(std::pair<std::string, std::vector<std::string>>(fileString, functionBody));
}

void StackMachineFileReader::skipComment(std::ifstream& fileStream, std::string& currentString)
{
	const std::string beginningOfComment = "#";

	while (currentString == beginningOfComment)
	{
		while (fileStream.peek() != '\n')
		{
			fileStream >> currentString;
		}

		fileStream >> currentString;
	}
}

void StackMachineFileReader::readTill(std::string symbol, std::ifstream& fileStream, std::string& currentString, std::vector<std::string>& functionBody)
{
	while (currentString != symbol && !fileStream.eof())
	{
		this->skipComment(fileStream, currentString);
		functionBody.push_back(currentString);
		fileStream >> currentString;
	}
}
