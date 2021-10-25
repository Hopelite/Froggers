#include "pch.h"
#include "StackMachineFileReader.h"
#include "NoSuchFileException.h"
#include <iostream>
#include <map>

StackMachineFileReader::StackMachineFileReader(const std::string& pathToFile)
{
	// TODO: Implement logic of skipping comments.

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
				while (currentString != "{")
				{
					fileStream >> currentString;
				}

				fileStream >> currentString;
				while (currentString != "}")
				{
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
	if (this->functions->find("main") == this->functions->end())
	{
		// TODO: Implement NoEntryPointException exception.
	}

	std::vector<std::string> mainBody = this->functions->find("main")->second;
	for (size_t i = 0; i < mainBody.size(); i++)
	{
		if (mainBody[i] == "push")
		{
			int number = std::stoi(mainBody[++i]);
			this->push(number);
		}
		else if (mainBody[i] == "pop")
		{
			this->pop();
		}
		else if (mainBody[i] == "peek")
		{
			this->peek();
		}
		else if (mainBody[i] == "dup")
		{
			this->duplicate();
		}
		else if (mainBody[i] == "add")
		{
			this->add();
		}
		else if (mainBody[i] == "sub")
		{
			this->subtract();
		}
		else if (mainBody[i] == "mul")
		{
			this->multiply();
		}
		else if (mainBody[i] == "div")
		{
			this->divide();
		}
	}
}
