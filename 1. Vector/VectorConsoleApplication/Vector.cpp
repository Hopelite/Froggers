#include "Vector.h"
#include <math.h>

Vector::Vector(double x, double y, double z)
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

Vector::~Vector()
{
	// TODO: implement deconstructor
}

double Vector::getLength()
{
	return sqrt(pow((this->x), 2) + pow((this->y), 2) + pow((this->z), 2)) * 100 / 100;
}

Vector& Vector::operator+(const Vector& rhs)
{
	Vector result(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
	return result;
}

Vector& Vector::operator+=(const Vector& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return *this;
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

Vector& Vector::operator=(const Vector& rhs)
{
	if (&rhs != this)
	{
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
	}

	return *this;
}

bool Vector::operator>(const Vector& rhs)
{
	if (this->x > rhs.x && this->y > rhs.y && this->z > rhs.z)
	{
		return true;
	}

	return false;
}

bool Vector::operator>=(const Vector& rhs)
{
	if (this->x >= rhs.x && this->y >= rhs.y && this->z >= rhs.z)
	{
		return true;
	}

	return false;
}

bool Vector::operator<(const Vector& rhs)
{
	// TODO: implement method
	return false;
}

bool Vector::operator<=(const Vector& rhs)
{
	// TODO: implement method
	return false;
}

bool Vector::operator==(const Vector& rhs)
{
	if (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z)
	{
		return true;
	}

	return false;
}

bool Vector::operator!=(const Vector& rhs)
{
	return false;
}

std::ostream& operator<<(std::ostream& out, const Vector& vector)
{
	// TODO: implement method
	return out;
}

std::istream& operator>>(std::istream& in, const Vector& vector)
{
	// TODO: implement method
	return in;
}