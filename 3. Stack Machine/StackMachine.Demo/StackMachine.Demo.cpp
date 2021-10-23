#include <iostream>
#include "..\StackMachine\Stack.h"
#include "..\StackMachine\StackIsEmptyException.h"
#include "..\StackMachine\StackMachine.h"

int main()
{
    // TODO: Stack (push, pop, peek, dup) + Stack Exceptions (Stack is empty)
    StackMachine machine;

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
    machine.duplicate();
    int count = machine.getCount();

    // TODO: EvaluationFunctions (mul, div, sub, add)

    // TODO: Logger (IObserver) + Stack (ISubject)

    // TODO: Parser

    std::cout << "Hello World!\n";
}
