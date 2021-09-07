#include "pch.h"
#include "CppUnitTest.h"
#include "..\VectorConsoleApplication\Vector.h"
#include "..\VectorConsoleApplication\Vector.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorTests
{
	TEST_CLASS(VectorTests)
	{
	public:
		
		TEST_METHOD(VectorTests_ConstructorAndGetter)
		{
			double x, y, z;
			Vector vector(2.00, 4.00, 0.00);
			vector.getCoords(x, y, z);

			Assert::AreEqual(x, 2.00);
			Assert::AreEqual(y, 4.00);
			Assert::AreEqual(z, 0.00);
		}
	};
}
