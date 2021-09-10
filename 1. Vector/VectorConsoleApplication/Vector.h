#pragma once
#include <iostream>

class Vector
{
	friend std::ostream& operator<<(std::ostream& out, const Vector& vector);
	friend std::istream& operator>>(std::istream& in, Vector& vector);

public:
	
	Vector(double x, double y, double z);
	Vector(const Vector& vector);

	void getCoords(double& x, double& y, double& z);
	void setCoords(double& x, double& y, double& z);

	double getX();
	void setX(const double& x);

	double getY();
	void setY(const double& y);

	double getZ();
	void setZ(const double& z);

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

	double operator^(const Vector& rhs);
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