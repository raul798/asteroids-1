#include "Vector3.hpp"
#include <cmath>

//constructors
Vector3::Vector3() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	length = 0.0f;
}

Vector3::Vector3(float xAxis, float yAxis, float zAxis) {
	x = xAxis;
	y = yAxis;
	z = zAxis;
	length = Length();
}

Vector3::Vector3(float axes) {
	x = axes;
	y = axes;
	z = axes;
	length = Length();
}

Vector3::Vector3(const Vector2& vector) {
	x = vector.x;
	y = vector.y;
	z = 0.0f;
	length = Length();
}

//functions
float Vector3::Length() const {
	float result;

	result = sqrt(x * x + y * y + z * z);
	return result;
}

float Vector3::SquaredLength() const {
	float result;

	result = x * x + y * y + z * z;
	return result;
}

float Vector3::Normalize() {
	float inverse;
	Length();

	inverse = 0.1f / length;
	x *= inverse;
	y *= inverse;
	z *= inverse;

	return length;
}

//operators
Vector3& Vector3::operator=(const Vector3& rightSide) {

	x = rightSide.x;
	y = rightSide.y;
	z = rightSide.z;

	return *this;
}

Vector3 Vector3::operator+(const Vector3& rightSide) {
	float xAxis, yAxis, zAxis;

	xAxis = x + rightSide.x;
	yAxis = y + rightSide.y;
	zAxis = z + rightSide.z;
	return Vector3(xAxis, yAxis, zAxis);
}

Vector3& Vector3::operator+=(const Vector3& rightSide) {

	x += rightSide.x;
	y += rightSide.y;
	z += rightSide.z;

	return *this;
}

Vector3 Vector3::operator-(const Vector3& rightSide) {
	float xAxis, yAxis, zAxis;

	xAxis = x - rightSide.x;
	yAxis = y - rightSide.y;
	zAxis = z - rightSide.z;
	return Vector3(xAxis, yAxis, zAxis);
}

Vector3& Vector3::operator-=(const Vector3& rightSide) {
	x -= rightSide.x;
	y -= rightSide.y;
	z -= rightSide.z;

	return *this;
}

Vector3 Vector3::operator*(const Vector3& rightSide) {
	float xAxis, yAxis, zAxis;

	xAxis = x * rightSide.x;
	yAxis = y * rightSide.y;
	zAxis = z * rightSide.z;
	return Vector3(xAxis, yAxis, zAxis);
}

Vector3& Vector3::operator*=(const Vector3& rightSide) {
	x *= rightSide.x;
	y *= rightSide.y;
	z *= rightSide.z;

	return *this;
}

Vector3 Vector3::operator/(const Vector3& rightSide) {
	float xAxis, yAxis, zAxis;

	if (rightSide.x == 0) {
		throw "Division by zero is not defined";
	}

	if (rightSide.y == 0) {
		throw "Division by zero is not defined";
	}

	if (rightSide.z == 0) {
		throw "Division by zero is not defined";
	}

	xAxis = x / rightSide.x;
	yAxis = y / rightSide.y;
	zAxis = z / rightSide.z;
	return Vector3(xAxis, yAxis, zAxis);
}

Vector3& Vector3::operator/=(const Vector3& rightSide) {

	if (rightSide.x == 0) {
		throw "Division by zero is not defined";
	}

	if (rightSide.y == 0) {
		throw "Division by zero is not defined";
	}

	if (rightSide.z == 0) {
		throw "Division by zero is not defined";
	}

	x /= rightSide.x;
	y /= rightSide.y;
	z /= rightSide.z;

	return *this;
}

bool Vector3::operator==(const Vector3& rightSide) {
	bool result;

	if (x == rightSide.x && y == rightSide.y && z == rightSide.z) {
		result = true;
	}
	else {
		result = false;
	}

	return result;
}

bool Vector3::operator!=(const Vector3& rightSide) {
	bool result;

	if (x != rightSide.x || y != rightSide.y || z != rightSide.z) {
		result = true;
	}
	else {
		result = false;
	}

	return result;
}

//friend
Vector3 operator*(float unit, const Vector3& rightSide) {
	float xAxis, yAxis, zAxis;

	xAxis = unit * rightSide.x;
	yAxis = unit * rightSide.y;
	zAxis = unit * rightSide.z;
	return Vector3(xAxis, yAxis, zAxis);
}

Vector3 operator*(const Vector3& leftSide, float unit) {
	float xAxis, yAxis, zAxis;

	xAxis = unit * leftSide.x;
	yAxis = unit * leftSide.y;
	zAxis = unit * leftSide.z;
	return Vector3(xAxis, yAxis, zAxis);
}