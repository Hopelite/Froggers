/// \file

#include "Vector.h"
#include <math.h>

Vector::Vector()
{
	this->x = 0.00;
	this->y = 0.00;
	this->z = 0.00;
}

Vector::Vector(const double x, const double y, const double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector::Vector(const Vector& vector)
{
	this->x = vector.x;
	this->y = vector.y;
	this->z = vector.z;
}

void Vector::getCoords(double& x, double& y, double& z)
{
	x = this->x;
	y = this->y;
	z = this->z;
}

void Vector::setCoords(const double& x, const double& y, const double& z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double Vector::getX()
{
	return this->x;
}

void Vector::setX(const double& x)
{
	this->x = x;
}

double Vector::getY()
{
	return this->y;
}

void Vector::setY(const double& y)
{
	this->y = y;
}

double Vector::getZ()
{
	return this->z;
}

void Vector::setZ(const double& z)
{
	this->z = z;
}

double Vector::getLength()
{
	return sqrt(pow((this->x), 2) + pow((this->y), 2) + pow((this->z), 2));
}

const Vector& Vector::operator=(const Vector& rhs)
{
	if (&rhs != this)
	{
	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;
	}

	return *this;
}

const Vector Vector::operator+(const Vector& rhs)
{
	Vector result;
	result.x = this->x + rhs.x;
	result.y = this->y + rhs.y;
	result.z = this->z + rhs.z;

	return result;
}

const Vector& Vector::operator+=(const Vector& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return *this;
}

const Vector Vector::operator-(const Vector& rhs)
{
	Vector result(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
	return result;
}

const Vector& Vector::operator-=(const Vector& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	return *this;
}

const Vector Vector::operator*(const Vector& rhs)
{
	Vector result((this->y * rhs.z - this->z * rhs.y), -(this->x * rhs.z - this->z * rhs.x), (this->x * rhs.y - this->y * rhs.x));
	return result;
}

const Vector& Vector::operator*=(const Vector& rhs)
{
	double x = this->x, y = this->y;

	this->x = this->y * rhs.z - this->z * rhs.y;
	this->y = -(x * rhs.z - this->z * rhs.x);
	this->z = x * rhs.y - y * rhs.x;
	return *this;
}

const Vector Vector::operator*(const double& rhs)
{
	Vector result(this->x * rhs, this->y * rhs, this->z * rhs);
	return result;
}

const Vector& Vector::operator*=(const double& rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;
	return *this;
}

const Vector Vector::operator/(const Vector& rhs)
{
	Vector result(this->x / rhs.x, this->y / rhs.y, this->z / rhs.z);
	return result;
	
}

const Vector& Vector::operator/=(const Vector& rhs)
{
	this->x /= rhs.x;
	this->y /= rhs.y;
	this->z /= rhs.z;
	return *this;
}

double Vector::operator^(const Vector& rhs)
{
	return (this->x * rhs.x + this->y * rhs.y + this->z * rhs.z) /
		(sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2)) * sqrt(pow(rhs.x, 2) + pow(rhs.y, 2) + pow(rhs.z, 2)));
}

bool Vector::operator>(Vector& rhs)
{
	return this->getLength() > rhs.getLength();
}

bool Vector::operator>=(Vector& rhs)
{
	return this->getLength() >= rhs.getLength();
}

bool Vector::operator<(Vector& rhs)
{
	if (this->getLength() < rhs.getLength())
	{
		return true;
	}

	return false;
}

bool Vector::operator<=(Vector& rhs)
{
	if (this->getLength() <= rhs.getLength())
	{
		return true;
	}

	return false;
}

const bool Vector::operator==(const Vector& rhs)
{
	if (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z)
	{
		return true;
	}

	return false;
}

bool Vector::operator!=(const Vector& rhs)
{	
	return !(*this == rhs);
}

const void Vector::operator++()
{
	x = this->x + 1;
	y = this->y + 1;
	z = this->z + 1;
}

std::ostream& operator<<(std::ostream& out, const Vector& vector)
{
	out << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
	return out;
}

std::istream& operator>>(std::istream& in, Vector& vector)
{
	in >> vector.x >> vector.y >> vector.z;
	return in;
}