#include <iostream>
#include "..\StackMachine\Stack.h"
#include "..\StackMachine\StackIsEmptyException.h"
#include "..\StackMachine\StackMachine.h"
#include "..\ConsoleLogger\ConsoleLogger.h"
#include "..\StackMachine\StackMachineFileReader.h"

// [x] TODO: Stack (push, pop, peek, dup) + Stack Exceptions (Stack is empty)

// [X] TODO: EvaluationFunctions (mul, div, sub, add)

// [X] TODO: Logger (IObserver) + Stack (ISubject)

// [X] TODO: Parser

int main()
{
    StackMachineFileReader fl("C:\\Users\\Admin\\source\\repos\\BSUIR\\inputFile.txt");

    // Uncomment next line to track program execution.
    //ConsoleLogger logger(&fl);
    fl.startReading();
}
