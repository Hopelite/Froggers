#pragma once
class TestClass
{
public:
	TestClass(int field);

	int getField();

	bool operator>(const TestClass& rhs);
	bool operator<(const TestClass& rhs);

private:
	int field;
};

