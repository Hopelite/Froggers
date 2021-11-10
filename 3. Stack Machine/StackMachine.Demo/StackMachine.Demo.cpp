#include <iostream>
#include "..\StackMachine\StackMachine.h"
#include "..\ConsoleLogger\ConsoleLogger.h"
#include "..\StackMachine\StackMachineFileReader.h"

void print(Stack* stack)
{
    std::cout << stack->pop() << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc > 3 && argc < 2)
    {
        std::cout << "Invalid number of input arguments. You can enter only <pathToFile> with additional \"-debug\" argument." << std::endl;
        return -1;
    }

    StackMachineFileReader fileReader(argv[1]);
    fileReader.addOuterFunction("print", print);
    ConsoleLogger* logger;
    if (argc == 3)
    {
        if (std::strcmp(argv[2], "-debug") == 0)
        {
            logger = new ConsoleLogger(&fileReader);
        }
        else
        {
            std::cout << "Invalid second argument. You can enter only additional \"-debug\" argument." << std::endl;
            return -1;
        }
    }

    try
    {
        fileReader.startParsing();
    }
    catch (const std::exception& ex)
    {
        std::cout << "Exception thrown" << ex.what() << std::endl;
        return -1;
    }
}
