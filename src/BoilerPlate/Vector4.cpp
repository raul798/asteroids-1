#include "Vector4.hpp"
#include <cmath>

//constructors
Vector4::Vector4() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
	length = 0.0f;
}

Vector4::Vector4(float xAxis, float yAxis, float zAxis, float wComponent) {
	x = xAxis;
	y = yAxis;
	z = zAxis;
	w = wComponent;
	length = Length();
}

Vector4::Vector4(float axesAndW) {
	x = axesAndW;
	y = axesAndW;
	z = axesAndW;
	w = axesAndW;
	length = Length();
}

Vector4::Vector4(const Vector2& vector) {
	x = vector.x;
	y = vector.y;
	z = 0.0f;
	w = 0.0f;
	length = Length();
}

Vector4::Vector4(const Vector3& vector) {
	x = vector.x;
	y = vector.y;
	z = vector.z;
	w = 0.0f;
	length = Length();
}

//functions
float Vector4::Length() const {
	float result;

	result = sqrt(x * x + y * y + z * z + w * w);
	return result;
}

float Vector4::SquaredLength() const {
	float result;

	result = x * x + y * y + z * z; 
	return result;
}

float Vector4::Normalize() {
	float inverse;
	Length();

	inverse = 0.1f / length;
	x *= inverse;
	y *= inverse;
	z *= inverse;

	return length;
}

//operators
Vector4& Vector4::operator=(const Vector4& rightSide) {

	x = rightSide.x;
	y = rightSide.y;
	z = rightSide.z;
	w = rightSide.w;

	return *this;
}

Vector4 Vector4::operator+(const Vector4& rightSide) {
	float xAxis, yAxis, zAxis, wComponent;

	xAxis = x + rightSide.x;
	yAxis = y + rightSide.y;
	zAxis = z + rightSide.z;
	wComponent = w + rightSide.w;

	return Vector4(xAxis, yAxis, zAxis, wComponent);
}

Vector4& Vector4::operator+=(const Vector4& rightSide) {

	x += rightSide.x;
	y += rightSide.y;
	z += rightSide.z;
	w += rightSide.w;

	return *this;
}

Vector4 Vector4::operator-(const Vector4& rightSide) {
	float xAxis, yAxis, zAxis, wComponent;

	xAxis = x - rightSide.x;
	yAxis = y - rightSide.y;
	zAxis = z - rightSide.z;
	wComponent = w - rightSide.w;

	return Vector4(xAxis, yAxis, zAxis, w);
}

Vector4& Vector4::operator-=(const Vector4& rightSide) {
	x -= rightSide.x;
	y -= rightSide.y;
	z -= rightSide.z;
	w -= rightSide.w;

	return *this;
}

Vector4 Vector4::operator*(const Vector4& rightSide) {
	float xAxis, yAxis, zAxis, wComponent;

	xAxis = x * rightSide.x;
	yAxis = y * rightSide.y;
	zAxis = z * rightSide.z;
	wComponent = w * rightSide.w;

	return Vector4(xAxis, yAxis, zAxis, w);
}

Vector4& Vector4::operator*=(const Vector4& rightSide) {
	x *= rightSide.x;
	y *= rightSide.y;
	z *= rightSide.z;
	w *= rightSide.w;

	return *this;
}

Vector4 Vector4::operator/(const Vector4& rightSide) {
	float xAxis, yAxis, zAxis, wComponent;

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
	wComponent = w / rightSide.w;

	return Vector4(xAxis, yAxis, zAxis, w);
}

Vector4& Vector4::operator/=(const Vector4& rightSide) {

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
	w /= rightSide.w;

	return *this;
}

bool Vector4::operator==(const Vector4& rightSide) {
	bool result;

	if (x == rightSide.x && y == rightSide.y && z == rightSide.z && w == rightSide.w) {
		result = true;
	}
	else {
		result = false;
	}

	return result;
}

bool Vector4::operator!=(const Vector4& rightSide) {
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
Vector4 operator*(float unit, const Vector4& rightSide) {
	float xAxis, yAxis, zAxis, wComponent;

	xAxis = unit * rightSide.x;
	yAxis = unit * rightSide.y;
	zAxis = unit * rightSide.z;
	wComponent = unit * rightSide.w;

	return Vector4(xAxis, yAxis, zAxis, wComponent);
}

Vector4 operator*(const Vector4& leftSide, float unit) {
	float xAxis, yAxis, zAxis, wComponent;

	xAxis = unit * leftSide.x;
	yAxis = unit * leftSide.y;
	zAxis = unit * leftSide.z;
	wComponent = unit * leftSide.w;

	return Vector4(xAxis, yAxis, zAxis, wComponent);
}