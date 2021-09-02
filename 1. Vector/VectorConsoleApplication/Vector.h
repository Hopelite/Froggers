#pragma once

class Vector
{
public:
	Vector(double x1, double y1, double z1, double x2, double y2, double z2);
	~Vector();
	double getLength();
	const Vector& operator+(const Vector& rhs);
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
	bool operator>(const Vector& rhs);
	bool operator>=(const Vector& rhs);
	bool operator<(const Vector& rhs);
	bool operator<=(const Vector& rhs);
	bool operator==(const Vector& rhs);
	bool operator!=(const Vector& rhs);

private:
	struct Point
	{
	public:
		friend class Vector;
		Point(double x, double y, double z);

	private:
		double x;
		double y;
		double z;
	};

	Point *startPoint;
	Point *endPoint;
};