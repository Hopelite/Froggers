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

void Vector::getCoords(double& x, double& y, double& z)
{
	x = this->x;
	y = this->y;
	z = this->z;
}

void Vector::setCoords(double& x, double& y, double& z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double Vector::getX()
{
	// TODO: implement get method
	return 0.0;
}

void Vector::setX(const double& x)
{
	// TODO: implement set method
}

double Vector::getY()
{
	// TODO: implement set method
	return 0.0;
}

void Vector::setY(const double& y)
{
	// TODO: implement set method
}

double Vector::getZ()
{
	// TODO: implement set method
	return 0.0;
}

void Vector::setZ(const double& z)
{
	// TODO: implement set method
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
	Vector result((this->y * rhs.z - this->z * rhs.y), -(this->x * rhs.z - this->z * rhs.x), (this->x * rhs.y - this->y * rhs.x));
	return result;
}

Vector& Vector::operator*=(const Vector& rhs)
{
	double x = this->x, y = this->y;

	this->x = this->y * rhs.z - this->z * rhs.y;
	this->y = -(x * rhs.z - this->z * rhs.x);
	this->z = x * rhs.y - y * rhs.x;
	return *this;
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
	return (this->x * rhs.x + this->y * rhs.y + this->z * rhs.z) /
		(sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2)) * sqrt(pow(rhs.x, 2) + pow(rhs.y, 2) + pow(rhs.z, 2)));
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
	{
		return true;
	}
	
	return false;
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