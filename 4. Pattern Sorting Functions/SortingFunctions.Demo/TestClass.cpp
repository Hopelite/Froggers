#include "TestClass.h"

TestClass::TestClass(int field)
{
    this->field = field;
}

int TestClass::getField()
{
    return this->field;
}

bool TestClass::operator>(const TestClass& rhs)
{
    return this->field > rhs.field;
}

bool TestClass::operator<(const TestClass& rhs)
{
    return this->field < rhs.field;
}
