#include "pch.h"
#include "StackMachineFileReader.h"
#include "NoSuchFileException.h"
#include <iostream>

StackMachineFileReader::StackMachineFileReader(const std::string& pathToFile)
{
	this->pathToFile = pathToFile;
}

void StackMachineFileReader::startReading()
{
	std::ifstream fileStream(this->pathToFile);
	if (!fileStream.is_open())
	{
		throw NoSuchFileException();
	}
	else
	{
		std::string fileString;
		int number = 0;
		while (!fileStream.eof())
		{
			fileStream >> fileString;

			if (fileString == "push")
			{
				fileStream >> number;
				this->push(number);
			}
			else if (fileString == "pop")
			{
				this->pop();
			}
			else if (fileString == "peek")
			{
				this->peek();
			}
			else if (fileString == "dup")
			{
				this->duplicate();
			}
			else if (fileString == "add")
			{
				this->add();
			}
			else if (fileString == "sub")
			{
				this->subtract();
			}
			else if (fileString == "mul")
			{
				this->multiply();
			}
			else if (fileString == "div")
			{
				this->divide();
			}
		}
	}

	fileStream.close();
}
