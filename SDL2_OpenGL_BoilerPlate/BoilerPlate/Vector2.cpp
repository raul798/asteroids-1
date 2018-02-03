#include "Vector2.hpp"
#include <cmath>

//constructors
Vector2::Vector2() {
	x = 0.0f;
	y = 0.0f;
	length = 0.0f;
}

Vector2::Vector2(float xAxis, float yAxis) {
	x = xAxis;
	y = yAxis;
	length = Length();

	
}

Vector2::Vector2(float axes) {
	x = axes;
	y = axes;
	length = Length();
}

//functions
float Vector2::Length() const { 
	float result;

	result = sqrt(x * x + y * y);
	return result;
}

float Vector2::SquaredLength() const { 
	float result;

	result = x * x + y * y;
	return result;
}

float Vector2::Normalize() {
	float inverse;
	Length();

	inverse = 0.1f / length;
	x *= inverse;
	y *= inverse;

	return length;
}

//operators
Vector2& Vector2::operator=(const Vector2& rightSide) {

	x = rightSide.x;
	y = rightSide.y;

	return *this;
}

Vector2 Vector2::operator+(const Vector2& rightSide) {
	float xAxis, yAxis;

	xAxis = x + rightSide.x;
	yAxis = y + rightSide.y;
	return Vector2(xAxis, yAxis);
}

Vector2& Vector2::operator+=(const Vector2& rightSide) {

	x += rightSide.x;
	y += rightSide.y;

	return *this;
}

Vector2 Vector2::operator-(const Vector2& rightSide) {
	float xAxis, yAxis;

	xAxis = x - rightSide.x;
	yAxis = y - rightSide.y;
	return Vector2(xAxis, yAxis);
}

Vector2& Vector2::operator-=(const Vector2& rightSide) {
	x -= rightSide.x;
	y -= rightSide.y;

	return *this;
}

Vector2 Vector2::operator*(const Vector2& rightSide) {
	float xAxis, yAxis;

	xAxis = x * rightSide.x;
	yAxis = y * rightSide.y;
	return Vector2(xAxis, yAxis);
}

Vector2& Vector2::operator*=(const Vector2& rightSide) {
	x *= rightSide.x;
	y *= rightSide.y;

	return *this;
}

Vector2 Vector2::operator/(const Vector2& rightSide) {
	float xAxis, yAxis;

	if (rightSide.x == 0) {
		throw "Division by zero is not defined";
	}

	if (rightSide.y == 0) {
		throw "Division by zero is not defined";
	}

	xAxis = x / rightSide.x;
	yAxis = y / rightSide.y;
	return Vector2(xAxis, yAxis);
}

Vector2& Vector2::operator/=(const Vector2& rightSide) {

	if (rightSide.x == 0) {
		throw "Division by zero is not defined";
	}

	if (rightSide.y == 0) {
		throw "Division by zero is not defined";
	}

	x /= rightSide.x;
	y /= rightSide.y;

	return *this;
}

bool Vector2::operator==(const Vector2& rightSide) {
	bool result;

	if (x == rightSide.x && y == rightSide.y) {
		result = true;
	}
	else {
		result = false;
	}

	return result;
}

bool Vector2::operator!=(const Vector2& rightSide) {
	bool result;

	if (x != rightSide.x || y != rightSide.y) {
		result = true;
	}
	else {
		result = false;
	}

	return result;
}

//friend
Vector2 operator*(float unit, const Vector2& rightSide) {
	float xAxis, yAxis;

	xAxis = unit * rightSide.x;
	yAxis = unit * rightSide.y;
	return Vector2(xAxis, yAxis);
}

Vector2 operator*(const Vector2& leftSide, float unit) {
	float xAxis, yAxis;

	xAxis = unit * leftSide.x;
	yAxis = unit * leftSide.y;
	return Vector2(xAxis, yAxis);
}