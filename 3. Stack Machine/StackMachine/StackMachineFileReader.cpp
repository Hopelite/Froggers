#include "pch.h"
#include "StackMachineFileReader.h"
#include <iostream>

StackMachineFileReader::StackMachineFileReader(const std::string& pathToFile)
{
	this->pathToFile = pathToFile;
}

void StackMachineFileReader::startReading()
{
	std::ifstream fileStream;
	fileStream.open(getPathToFile());
	if (!fileStream.is_open())
	{
		throw NoSuchFileException();
	}
	else
	{
		std::string fileString{""};
		StackMachine exempl;
		int number = 0;
		while (!fileStream.eof())
		{
			fileStream >> fileString;

			if(fileString == "push") fileStream >> number;

			if (fileString == "push")
			{
				exempl.push(number);
			} 

			else if (fileString == "pop")
			{
				exempl.pop();
			}

			else if (fileString == "peek")
			{
				exempl.peek();
			}

			else if (fileString == "dup")
			{
				exempl.duplicate();
			}

			else if (fileString == "add")
			{
				exempl.add();
			}

			else if (fileString == "sub")
			{
				exempl.subtract();
			}

			else if (fileString == "mul")
			{
				exempl.multiply();
			}

			else if (fileString == "div")
			{
				exempl.divide();
			}

			else
			{
				std::cout << "Logic in devoloping\n";
			}
		}

	}
	fileStream.close();
}
