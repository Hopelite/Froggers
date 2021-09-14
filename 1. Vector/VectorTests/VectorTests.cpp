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

			// Arrange
			Vector defaultVector;
			defaultVector.getCoords(x, y, z);

			// Assert
			Assert::AreEqual(0.00, x);
			Assert::AreEqual(0.00, y);
			Assert::AreEqual(0.00, z);

			// Arrange
			Vector copyingVector(12, 14, 15);
			copyingVector.getCoords(x, y, z);
			Vector copyVector(copyingVector);

			// Assert
			Assert::AreEqual(copyVector.getX(), x);
			Assert::AreEqual(copyVector.getY(), y);
			Assert::AreEqual(copyVector.getZ(), z);
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
			Vector firstVector(1.00, 2.00, -2.00);

			// Assert
			for (double i = -15; i <= 15; i++)
			{
				Vector sumVector(i + 1, i -2, i - 14);
				Vector result = sumVector + firstVector;
				Assert::IsTrue(result.getX() == firstVector.getX() + i + 1);
				Assert::IsTrue(result.getY() == firstVector.getY() + i - 2);
				Assert::IsTrue(result.getZ() == firstVector.getZ() + i - 14);

				Vector substractionVector(i + 1, i - 2, i - 14);
				result = firstVector - substractionVector;
				Assert::IsTrue(result.getX() == firstVector.getX() - (i + 1));
				Assert::IsTrue(result.getY() == firstVector.getY() - (i - 2));
				Assert::IsTrue(result.getZ() == firstVector.getZ() - (i - 14));

				result = firstVector * i;
				Assert::IsTrue(result.getX() == firstVector.getX() * i);
				Assert::IsTrue(result.getY() == firstVector.getY() * i);
				Assert::IsTrue(result.getZ() == firstVector.getZ() * i);

				Vector divisionVector(i + 1, i - 2, i - 14);
				result = divisionVector / firstVector;
				Assert::IsTrue(result.getX() == (i + 1) / firstVector.getX());
				Assert::IsTrue(result.getY() == (i - 2) / firstVector.getY());
				Assert::IsTrue(result.getZ() == (i - 14) / firstVector.getZ());
			}

			for (double i = -10; i <= 10; i++)
			{
				Vector secondVector(i + 1, i, i - 1);
				double cosine = ((i + 1) * firstVector.getX() + i * firstVector.getY() + (i - 1) * firstVector.getZ()) /
					(sqrt(pow(i, 2) + pow(i + 1, 2) + pow(i - 1, 2)) * sqrt(pow(firstVector.getX(), 2) + pow(firstVector.getY(), 2) + pow(firstVector.getZ(), 2)));

				double result = firstVector ^ secondVector;
				Assert::IsTrue(cosine == (firstVector ^ secondVector));
			}

			for (double i = -15; i <= 15; i++)
			{
				Vector secondVector(-i, i - 12, i + 13);
				secondVector += firstVector;
				Assert::IsTrue(-i + firstVector.getX() == secondVector.getX());
				Assert::IsTrue(i - 12 + firstVector.getY() == secondVector.getY());
				Assert::IsTrue(i + 13 + firstVector.getZ() == secondVector.getZ());
			}

			for (double i = -15; i <= 15; i++)
			{
				Vector secondVector(-i, i - 12, i + 13);
				secondVector -= firstVector;
				Assert::IsTrue(-i - firstVector.getX() == secondVector.getX());
				Assert::IsTrue(i - 12 - firstVector.getY() == secondVector.getY());
				Assert::IsTrue(i + 13 - firstVector.getZ() == secondVector.getZ());
			}

			for (double i = -15; i <= 15; i++)
			{
				Vector secondVector(-i, i - 12, i + 13);
				secondVector /= firstVector;
				Assert::IsTrue(-i / firstVector.getX() == secondVector.getX());
				Assert::IsTrue((i - 12) / firstVector.getY() == secondVector.getY());
				Assert::IsTrue((i + 13) / firstVector.getZ() == secondVector.getZ());
			}

			for (double i = -15; i <= 15; i++)
			{
				Vector multiplication = firstVector * i;
				Assert::IsTrue(i * firstVector.getX() == multiplication.getX());
				Assert::IsTrue(i * firstVector.getY() == multiplication.getY());
				Assert::IsTrue(i * firstVector.getZ() == multiplication.getZ());
			}
		}

		TEST_METHOD(VectorTests_VectorMultiplication)
		{
			Vector firstVector(1.00, 2.00, -2.00);
			for (double i = -15; i <= 15; i++)
			{
				Vector secondVector(7 - i, 11 + i, i);
				Vector multiplication = firstVector * secondVector;
				Assert::IsTrue((firstVector.getY() * i - firstVector.getZ() * (11 + i)) == multiplication.getX());
				Assert::IsTrue(-(firstVector.getX() * i - firstVector.getZ() * (7 - i)) == multiplication.getY());
				Assert::IsTrue((firstVector.getX() * (11 + i) - firstVector.getY() * (7 - i)) == multiplication.getZ());
			}

			for (double i = -15; i <= 15; i++)
			{
				Vector secondVector(7 - i, 11 + i, i);
				secondVector *= firstVector;
				Assert::IsTrue((firstVector.getZ() * (11 + i) - firstVector.getY() * i) == secondVector.getX());
				Assert::IsTrue(-((7 - i) * firstVector.getZ() - i * firstVector.getX()) == secondVector.getY());
				Assert::IsTrue((firstVector.getY() * (7 - i) - firstVector.getX() * (11 + i)) == secondVector.getZ());
			}
		}
	};
}
