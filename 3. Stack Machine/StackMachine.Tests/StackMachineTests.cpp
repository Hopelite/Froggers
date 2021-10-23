#include "pch.h"
#include "CppUnitTest.h"
#include "..\StackMachine\StackMachine.h"
#include "..\StackMachine\StackIsEmptyException.h"
#include "..\StackMachine\NotEnoughOperandsException.h"
#include "..\StackMachine\DivisionByZeroException.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackMachineTests
{
	TEST_CLASS(StackMachineTests)
	{
	public:
		TEST_METHOD(StackMachineTests_Peek)
		{
			Stack stack;
			for (int i = 0; i < 100; i++)
			{
				stack.push(i);
				Assert::AreEqual(i, stack.peek());
			}
		}

		TEST_METHOD(StackMachineTests_PushAndPop)
		{
			Stack stack;
			for (int i = 0; i < 100; i++)
			{
				stack.push(i);
				Assert::AreEqual(i, stack.peek());
				Assert::AreEqual(i + 1, stack.getCount());
			}

			for (int i = 99; i > 0; i--)
			{
				Assert::AreEqual(i, stack.pop());
				Assert::AreEqual(i - 1, stack.peek());
				Assert::AreEqual(i, stack.getCount());
			}
		}

		TEST_METHOD(StackMachineTests_Duplicate)
		{
			Stack stack;
			stack.push(5);

			for (int i = 0; i < 100; i++)
			{
				stack.duplicate();
				Assert::AreEqual(5, stack.peek());
				Assert::AreEqual(i + 2, stack.getCount());
			}
		}

		TEST_METHOD(StackMachineTests_Pop_StackIsEmpty_ThrowsStackIsEmptyException)
		{
			auto func = [] 
			{
				Stack stack;
				stack.pop();
			};

			Assert::ExpectException<StackIsEmptyException>(func);
		}

		TEST_METHOD(StackMachineTests_Add)
		{
			StackMachine machine;
			int current = 1;
			machine.push(1);
			for (int i = 0; i < 100; i++)
			{
				machine.push(i);
				machine.add();
				Assert::AreEqual(current + i, machine.peek());
				current = machine.peek();
			}
		}

		TEST_METHOD(StackMachineTests_Subtract)
		{
			StackMachine machine;
			int current = 100;
			machine.push(100);
			for (int i = 1; i <= 10; i++)
			{
				machine.push(i * 10);
				machine.subtract();
				Assert::AreEqual(current - (i * 10), machine.peek());
				current = machine.peek();
			}
		}

		TEST_METHOD(StackMachineTests_Multiply)
		{
			StackMachine machine;
			int current = 0;
			machine.push(1);
			for (int i = 0; i < 100; i++)
			{
				machine.push(i);
				machine.multiply();
				Assert::AreEqual(current * i, machine.peek());
				current = machine.peek();
			}
		}

		TEST_METHOD(StackMachineTests_Divide)
		{
			StackMachine machine;
			int current = 100;
			machine.push(100);
			for (int i = 1; i < 25; i++)
			{
				machine.push(i);
				machine.divide();
				Assert::AreEqual(current / i, machine.peek());
				current = machine.peek();
			}
		}

		TEST_METHOD(StackMachineTests_ZeroOperands_ThrowsNotEnoughOperandsException)
		{
			auto func = []
			{
				StackMachine machine;
				machine.add();
			};

			Assert::ExpectException<NotEnoughOperandsException>(func);
		}

		TEST_METHOD(StackMachineTests_OnlyOneOperand_ThrowsNotEnoughOperandsException)
		{
			auto func = []
			{
				StackMachine machine;
				machine.push(1);
				machine.add();
			};

			Assert::ExpectException<NotEnoughOperandsException>(func);
		}

		TEST_METHOD(StackMachineTests_DivideByZero_ThrowsDivisionByZeroException)
		{
			auto func = []
			{
				StackMachine machine;
				machine.push(1);
				machine.push(0);
				machine.divide();
			};

			Assert::ExpectException<DivisionByZeroException>(func);
		}
	};
}
