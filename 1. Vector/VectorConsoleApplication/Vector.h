#pragma once
#include <iostream>

/// \brief Class that represents a mathematical three-dimensional vector.
/// \details Laboratory work of students of group 021702 of the IIT Department (Faculty of Information Technologies and Control, BSUIR).
/// \authors Vadim Kurdesov, Daniil Pishch, Veronica Yatskova, Anastasia Degtereva
/// \include Vector.cpp
class Vector
{
	/// \brief Overrided insertion operator.
	/// \param[out] out ostream object to insert in.
	/// \param[in] vector Vector to insert from.
	/// \details Inserts data in this format: "('x coordinate', 'y coordinate', 'z coordinate')".
	friend std::ostream& operator<<(std::ostream& out, const Vector& vector);
	/// \brief Overrided extraction operator.
	/// \param[in] in istream object to extract from.
	/// \param[out] vector Vector to extract in.
	/// \details Extracts data in this format: 'x coordinate' 'y coordinate' 'z coordinate'.
	friend std::istream& operator>>(std::istream& in, Vector& vector);

public:

	/// \brief Default Vector constructor which initializes new Vector object with coordinates equal to zero.
	Vector();
	/// \brief Initializes new Vector object with specified coordinates.
	/// \param[in] x New vector 'x' coordinate.
	/// \param[in] y New vector 'y' coordinate.
	/// \param[in] z New vector 'z' coordinate.
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
	/// \details This method calculates vector length using $\sqrt{(x_2-x_1)^2+(y_2-y_1)^2+(x_2-x_1)}$ formula.
	/// \return Vector length.
	double getLength();

	/// \brief Operator '+' that adds vectors.
	/// \return New vector with summarized coordinates of left and right operands.
	const Vector operator+(const Vector& rhs);
	/// \brief Operator '+=' that adds vectors and assigns result to the left operand.
	/// \return Reassigned vector with summarized coordinates of left and right operands.
	const Vector& operator+=(const Vector& rhs);

	/// \brief Operator '-' that subtracts vectors.
	/// \return New vector with subtracted coordinates of left and right operands.
	const Vector operator-(const Vector& rhs);
	/// \brief Operator '-=' that subtracts vectors and assigns result to the left operand.
	/// \return Reassigned vector with subtracted coordinates of left and right operands.
	const Vector& operator-=(const Vector& rhs);

	/// \brief Operator '*' that multiplies vectors.
	/// \return New vector according to scalar multiplication.
	const Vector operator*(const Vector& rhs);
	/// \brief Operator '*=' that multiplies vectors and assigns result to the left operand.
	/// \return Reassigned vector according to scalar multiplication.
	const Vector& operator*=(const Vector& rhs);

	/// \brief Operator '*' that multiplies vector by number.
	/// \return New vector with multiplied by number coordinates.
	const Vector operator*(const double& rhs);
	/// \brief Operator '*=' that multiplies vector by number and assigns result to the left operand.
	/// \return Reassigned vector with multiplied by number coordinates.
	const Vector& operator*=(const double& rhs);

	/// \brief Operator '/' that divides vectors.
	/// \return New vector with divided coordinates of left and right operands.
	const Vector operator/(const Vector& rhs);
	/// \brief Operator '/=' that divides vectors and assigns result to the left operand.
	/// \return Reassigned vector with divided coordinates of left and right operands.
	const Vector& operator/=(const Vector& rhs);

	/// \brief Operator '^' that gets cosine between two vectors.
	/// \return Cosine between two vectors.
	double operator^(const Vector& rhs);
	/// \brief Assigns vector to current.
	/// \return Assigned left vector if it wasn't equal to the right vector.
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
	const bool operator==(const Vector& rhs);
	/// \brief Operator '!=' that compares vectors according to their length.
	/// \return True if left operand isn't equal to the right; false otherwise.	
	bool operator!=(const Vector& rhs);

	/// \brief Prefix operator '++' that increments all vector coordinates by 1.
	const void operator++();

private:
	double x;
	double y;
	double z;
};