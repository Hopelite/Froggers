#include "pch.h"
#include "StackMachineFileReader.h"
#include "NoSuchFileException.h"
#include "NoSuchFunctionException.h"
#include "NoReturnPointException.h"
#include <iostream>
#include <map>

StackMachineFileReader::StackMachineFileReader(const std::string& pathToFile)
{
	this->functions = new std::map<std::string, std::vector<std::string>>;

	std::ifstream fileStream(pathToFile);
	if (!fileStream.is_open())
	{
		throw NoSuchFileException();
	}
	else
	{
		std::string fileString;
		while (!fileStream.eof())
		{
			fileStream >> fileString;
			if (fileString == "function")
			{
				fileStream >> fileString;
				std::string currentString;
				std::vector<std::string> functionBody;
				fileStream >> currentString;
				while (currentString != "{" && !fileStream.eof())
				{
					fileStream >> currentString;
				}

				fileStream >> currentString;
				while (currentString != "}" && !fileStream.eof())
				{
					// Logic of skipping comments.
					if (currentString == "#")
					{
						while (fileStream.peek() != '\n')
						{
							fileStream >> currentString;
						}

						fileStream >> currentString;
					}

					functionBody.push_back(currentString);
					fileStream >> currentString;
				}

				this->functions->insert(std::pair<std::string, std::vector<std::string>>(fileString, functionBody));
			}
		}
	}

	fileStream.close();
}

StackMachineFileReader::~StackMachineFileReader()
{
	delete this->functions;
}

void StackMachineFileReader::startReading()
{
	this->parseFunction("main");
}

void StackMachineFileReader::parseFunction(std::string functionName)
{
	if (this->functions->find(functionName) == this->functions->end())
	{
		this->notify("Thrown exception: NoSuchFunctionException. Can't find function \"" + functionName + "\".\n");
		throw NoSuchFunctionException(functionName);
	}

	std::vector<std::string> functionBody = this->functions->find(functionName)->second;
	for (size_t i = 0; i < functionBody.size(); i++)
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
			std::string label = functionBody[++i] + ":";

			if (lhs == rhs)
			{
				while (i < functionBody.size() && functionBody[i] != label)
				{
					i++;
				}

				if (i == functionBody.size())
				{
					// TODO: Implement NoSuchLabelException exception.
				}
			}
		}
		else if (functionBody[i] == "return")
		{
			return;
		}
		else if (functionBody[i] == "callext")
		{
			std::cout << this->pop();
		}
	}

	// If there is no "return" operator in function, throw an exception.
	this->notify("Thrown exception: NoReturnPointException. Function \"" + functionName + "\" has no \"return\" operator.\n");
	throw NoReturnPointException(functionName);
}
