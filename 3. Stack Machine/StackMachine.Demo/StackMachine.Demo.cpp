#include <iostream>
#include "..\StackMachine\StackMachine.h"

int main()
{
    // TODO: Stack (push, pop, peek, dup) + Stack Exceptions (Stack is empty)
    StackMachine machine;
    machine.push(1);
    machine.push(2);
    machine.push(3);
    int count = machine.getCount();

    // TODO: EvaluationFunctions (mul, div, sub, add)

    // TODO: Logger (IObserver) + Stack (ISubject)

    // TODO: Parser

    std::cout << "Hello World!\n";
}
