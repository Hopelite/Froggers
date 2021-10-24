#include <iostream>
#include "..\StackMachine\Stack.h"
#include "..\StackMachine\StackIsEmptyException.h"
#include "..\StackMachine\StackMachine.h"
#include "..\ConsoleLogger\ConsoleLogger.h"
#include "..\StackMachine\StackMachineFileReader.h"

// [x] TODO: Stack (push, pop, peek, dup) + Stack Exceptions (Stack is empty)

// [X] TODO: EvaluationFunctions (mul, div, sub, add)

// [X] TODO: Logger (IObserver) + Stack (ISubject)

// [ ] TODO: Parser

int main()
{
    /*StackMachine machine;
    ConsoleLogger logger(&machine);

    try
    {
        machine.duplicate();
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what();
    }

    machine.push(1);
    machine.push(2);
    machine.push(3);
    machine.add();
    machine.duplicate();
    machine.multiply();
    machine.divide();
    */
    //int count = machine.getCount();
    StackMachineFileReader fl("D:\\PPVS_clone\\3. Stack Machine\\StackMachine.Demo\\inputFile.txt");
    fl.startReading();
}
