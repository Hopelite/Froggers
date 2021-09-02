#include "Vector.h"

Vector::Vector(double x1, double y1, double z1, double x2, double y2, double z2)
{
	this->startPoint = new Vector::Point(x1, y1, z1);
	this->endPoint = new Vector::Point(x2, y2, z2);
}

Vector::~Vector()
{
}

double Vector::getLength()
{
	// TODO: insert return statement here
}

const Vector& Vector::operator+(const Vector& rhs)
{
	// TODO: insert return statement here
}

Vector& Vector::operator+=(const Vector& rhs)
{
	// TODO: insert return statement here
}

const Vector& Vector::operator-(const Vector& rhs)
{
	// TODO: insert return statement here
}

Vector& Vector::operator-=(const Vector& rhs)
{
	// TODO: insert return statement here
}

const Vector& Vector::operator*(const Vector& rhs)
{
	// TODO: insert return statement here
}

Vector& Vector::operator*=(const Vector& rhs)
{
	// TODO: insert return statement here
}

const Vector& Vector::operator*(const double& rhs)
{
	// TODO: insert return statement here
}

Vector& Vector::operator*=(const double& rhs)
{
	// TODO: insert return statement here
}

const Vector& Vector::operator/(const Vector& rhs)
{
	// TODO: insert return statement here
}

Vector& Vector::operator/=(const Vector& rhs)
{
	// TODO: insert return statement here
}

const Vector& Vector::operator^(const Vector& rhs)
{
	// TODO: insert return statement here
}

bool Vector::operator>(const Vector& rhs)
{
	return false;
}

bool Vector::operator>=(const Vector& rhs)
{
	return false;
}

bool Vector::operator<(const Vector& rhs)
{
	return false;
}

bool Vector::operator<=(const Vector& rhs)
{
	return false;
}

bool Vector::operator==(const Vector& rhs)
{
	return false;
}

bool Vector::operator!=(const Vector& rhs)
{
	return false;
}

Vector::Point::Point(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
