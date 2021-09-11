#pragma once
#include <iostream>

/// \brief Class that represents a mathematical three-dimensional vector.
/// \details Details are not specified.
/// \authors Vadim Kurdesov, Daniil Pishch, Veronica Yatskova, Anastasia Degtereva
class Vector
{
	friend std::ostream& operator<<(std::ostream& out, const Vector& vector);
	friend std::istream& operator>>(std::istream& in, Vector& vector);

public:
	
	/// \brief Initializes new Vector object with specified coordinates.
	/// \param[in] x New vector 'x' coordinate.
	/// \param[in] y New vector 'y' coordinate.
	/// \brief Sets vector 'z' coordinate.
	Vector(const double x, const double y, const double z);
	/// \brief Initializes new Vector object copying other vector.
	/// \param[in] vector Vector to copy.
	Vector(const Vector& vector);

	/// \brief Gets all vector coordinates.
	/// \param[out] x Vector 'x' coordinate.
	/// \param[out] y Vector 'y' coordinate.
	/// \param[out] z Vector 'z' coordinate.
	void getCoords(double& x, double& y, double& z);
	/// \brief Gets all vector coordinates.
	/// \param[in] x New vector 'x' coordinate.
	/// \param[in] y New vector 'y' coordinate.
	/// \param[in] z New vector 'z' coordinate.
	void setCoords(const double& x, const double& y, const double& z);

	/// \brief Gets vector 'x'$ coordinate.
	double getX();
	/// \brief Sets vector 'x' coordinate.
	/// \param[in] x New vector 'x' coordinate.
	void setX(const double& x);

	/// \brief Gets vector 'y' coordinate.
	double getY();
	/// \brief Sets vector 'y' coordinate.
	/// \param[in] y New vector 'y' coordinate.
	void setY(const double& y);

	/// \brief Gets vector 'z' coordinate.
	double getZ();
	/// \brief Sets vector 'z' coordinate.
	/// \param[in] z New vector 'z' coordinate.
	void setZ(const double& z);

	/// \brief Calculates current vector length.
	/// \return Double value of vector length.
	double getLength();

	/// \brief Operator '+' that adds vectors.
	/// \return New vector with summarized coordinates of left and right operands.
	const Vector& operator+(const Vector& rhs);
	const Vector& operator+=(const Vector& rhs);

	/// \brief Operator '-' that subtracts vectors.
	/// \return New vector with subtracted coordinates of left and right operands.
	const Vector& operator-(const Vector& rhs);
	const Vector& operator-=(const Vector& rhs);

	/// \brief Operator '*' that multiplies vectors.
	/// \return New vector according to scalar multiplication.
	const Vector& operator*(const Vector& rhs);
	const Vector& operator*=(const Vector& rhs);

	/// \brief Operator '*' that multiplies vector by number.
	/// \return New vector with multiplied by number coordinates.
	const Vector& operator*(const double& rhs);
	const Vector& operator*=(const double& rhs);

	/// \brief Operator '/' that divides vectors.
	/// \return New vector with divided coordinates of left and right operands.
	const Vector& operator/(const Vector& rhs);
	const Vector& operator/=(const Vector& rhs);

	double operator^(const Vector& rhs);
	const Vector& operator=(const Vector& rhs);

	/// \brief Operator '>' that compares vectors according to their length.
	/// \return True if left operand is greater than right; false otherwise.
	bool operator>(Vector& rhs);
	/// \brief Operator '>=' that compares vectors according to their length.
	/// \return True if left operand is greater than or equal right; false otherwise.
	bool operator>=(Vector& rhs);
	
	/// \brief Operator '<' that compares vectors according to their length.
	/// \return True if left operand is less than right; false otherwise.
	bool operator<(Vector& rhs);
	/// \brief Operator '<=' that compares vectors according to their length.
	/// \return True if left operand is less than or equal right; false otherwise.
	bool operator<=(Vector& rhs);

	/// \brief Operator '==' that compares vectors according to their length.
	/// \return True if left operand equals right; false otherwise.
	bool operator==(const Vector& rhs);
	/// \brief Operator '!=' that compares vectors according to their length.
	/// \return True if left operand isn't equal to the right; false otherwise.
	bool operator!=(const Vector& rhs);

private:
	double x;
	double y;
	double z;
};