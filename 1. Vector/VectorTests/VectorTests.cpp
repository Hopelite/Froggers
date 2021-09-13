#include "pch.h"
#include "CppUnitTest.h"
#include "..\VectorConsoleApplication\Vector.h"
#include "..\VectorConsoleApplication\Vector.cpp"
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorTests
{
	TEST_CLASS(VectorTests)
	{
	public:
		
		TEST_METHOD(VectorTests_ConstructorAndGetters)
		{
			// Arrange
			double x, y, z;
			Vector vector(2.00, -4.00, 0.00);
			vector.getCoords(x, y, z);

			// Assert
			Assert::AreEqual(2.00, x);
			Assert::AreEqual(-4.00, y);
			Assert::AreEqual(0.00, z);

			Assert::AreEqual(x, vector.getX());
			Assert::AreEqual(y, vector.getY());
			Assert::AreEqual(z, vector.getZ());
		}

		TEST_METHOD(VectorTests_ConstructorAndSetters)
		{
			// Arrange
			double x, y, z;
			Vector vector(-5.01, -1.25, 7.167);
			vector.getCoords(x, y, z);

			// Assert
			Assert::AreEqual(-5.01 ,x);
			Assert::AreEqual(-1.25, y);
			Assert::AreEqual(7.167, z);

			// Arrange
			x = 0.00, y = 12.0, z = 12345.09876;
			vector.setCoords(x, y, z);

			// Assert
			Assert::AreEqual(0.00, vector.getX());
			Assert::AreEqual(12.0, vector.getY());
			Assert::AreEqual(12345.09876, vector.getZ());
		}

		TEST_METHOD(VectorTests_GetLength)
		{
			// Arrange
			Vector vector(2.00, 4.00, 4.00);

			// Assert
			Assert::AreEqual(6.0, vector.getLength());

			// Arrange
			double x = -1.00, y = 0.00, z = -3.00;
			vector.setCoords(x, y, z);

			// Assert
			Assert::AreEqual(3.0, floor(vector.getLength()));

			// Arrange
			x = 0.00, y = 0.00, z = 0.00;
			vector.setCoords(x, y, z);

			// Assert
			Assert::AreEqual(0.00, vector.getLength());
		}

		TEST_METHOD(VectorTests_EqualityAndComparisonOperators)
		{
			// Arrange
			Vector firstVector(1.00, 2.00, 3.00), secondVector(1.00, 2.00, 3.00);

			// Assert
			Assert::IsTrue(firstVector == secondVector);
			Assert::IsFalse(firstVector != secondVector);

			// Arrange
			double x = 1.01, y = 2.00, z = 3.00;
			secondVector.setCoords(x, y, z);

			// Assert
			Assert::IsTrue(firstVector < secondVector);
			Assert::IsFalse(firstVector > secondVector);

			// Arrange
			firstVector.setCoords(x, y, z);

			// Assert
			Assert::IsTrue(firstVector <= secondVector);
			Assert::IsTrue(firstVector >= secondVector);

			// Arrange
			x = 99.9, y = 123.0, z = 12;
			firstVector.setCoords(x, y, z);

			// Assert
			Assert::IsTrue(firstVector >= secondVector);
			Assert::IsFalse(firstVector <= secondVector);
		}

		TEST_METHOD(VectorTests_MathematicalOperators)
		{
			// Arrange
			Vector firstVector(1.00, 2.00, 3.00), secondVector(1.00, 3.00, 5.00);

			// Assert
			Vector firstExpected(2.00, 5.00, 8.00), secondExpected(0.00, -1.00, -2.00), thirdExpected(0.00, 1.00, 2.00), actual;
			actual = firstVector + secondVector;

			//Assert::AreEqual(firstExpected, actual);

			actual = secondVector + firstVector;
			//Assert::AreEqual(firstExpected, actual);

			actual = firstVector - secondVector;
			//Assert::AreEqual(secondExpected, actual);

			actual = secondVector - firstVector;
			//Assert::AreEqual(thirdExpected, actual);
		}
	};
}
