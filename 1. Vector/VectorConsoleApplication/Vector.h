#pragma once
#include <iostream>

class Vector
{
	friend std::ostream& operator<<(std::ostream& out, const Vector& vector);
	friend std::istream& operator>>(std::istream& in, Vector& vector); //без CONST!!!

public:
	
	Vector(); //конструктор по умолчанию. без него не принимает запись || Vector a; ||
	Vector(double x, double y, double z);
	Vector(const Vector& vector);

	~Vector();

	double getLength();

	Vector& operator+(const Vector& rhs);
	Vector& operator+=(const Vector& rhs);

	const Vector& operator-(const Vector& rhs);
	Vector& operator-=(const Vector& rhs);

	const Vector& operator*(const Vector& rhs);
	Vector& operator*=(const Vector& rhs);

	const Vector& operator*(const double& rhs);
	Vector& operator*=(const double& rhs);

	const Vector& operator/(const Vector& rhs);
	Vector& operator/=(const Vector& rhs);
	const Vector& operator^(const Vector& rhs);

	Vector& operator=(const Vector& rhs);

	bool operator>(Vector& rhs);
	bool operator>=(Vector& rhs);

	bool operator<(Vector& rhs);
	bool operator<=(Vector& rhs);

	bool operator==(const Vector& rhs);
	bool operator!=(const Vector& rhs);

private:
	double x;
	double y;
	double z;
};