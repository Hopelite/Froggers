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
	Vector result(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
	return result;
}

Vector& Vector::operator-=(const Vector& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	return *this;
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
	Vector result(this->x * rhs, this->y * rhs, this->z * rhs);
	return result;
}

Vector& Vector::operator*=(const double& rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;
	return *this;
}

const Vector& Vector::operator/(const Vector& rhs)
{
	Vector result(this->x / rhs.x, this->y / rhs.y, this->z / rhs.z);
	return result;
	
}

Vector& Vector::operator/=(const Vector& rhs)
{
	this->x /= rhs.x;
	this->y /= rhs.y;
	this->z /= rhs.z;
	return *this;
}

double Vector::operator^(const Vector& rhs) 
{
	double result((this->x * rhs.x + this->y * rhs.y + this->z * rhs.z)/
		(sqrt(pow(this->x,2)+ pow(this->y, 2)+ pow(this->z, 2))*sqrt(pow(rhs.x, 2) + pow(rhs.y, 2) + pow(rhs.z, 2)));
	return result;
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

bool Vector::operator>(Vector& rhs)
{
	if (this->getLength() > rhs.getLength())
	{
		return true;
	}

	return false;
}

bool Vector::operator>=(Vector& rhs)
{
	if (this->getLength() >= rhs.getLength())
	{
		return true;
	}

	return false;
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
	if (this->x != rhs.x || this->y != rhs.y || this->z != rhs.z)
		return true;
	else return false;
}

std::ostream& operator<<(std::ostream& out, const Vector& vector)
{
	// TODO: implement method
	out << "Vector(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
	return out;
}

std::istream& operator>>(std::istream& in, Vector& vector)
{
	// TODO: implement method
	in >> vector.x;
	in >> vector.y;
	in >> vector.z;
	return in;
}