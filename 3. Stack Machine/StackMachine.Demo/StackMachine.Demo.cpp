#include <iostream>
#include "..\StackMachine\Stack.h"
#include "..\StackMachine\StackIsEmptyException.h"
#include "..\StackMachine\StackMachine.h"
#include "..\ConsoleLogger\ConsoleLogger.h"
#include "..\StackMachine\StackMachineFileReader.h"

int main(int argc, char* argv[])
{
    if (argc > 3)
    {
        std::cout << "Invalid number of input arguments. You can enter only <pathToFile> with additional \"-debug\" argument." << std::endl;
        return -1;
    }

    StackMachineFileReader fileReader(argv[1]);
    ConsoleLogger* logger;
    if (argc == 3 && std::strcmp(argv[2], "-debug") == 0)
    {
        logger = new ConsoleLogger(&fileReader);
    }

    fileReader.startReading();
}
