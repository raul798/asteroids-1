#pragma once
#include "Vector3.hpp"

struct Vector4 {

	//members
	float x;
	float y;
	float z;
	float w;
	float length;

	//constructors
	Vector4();
	Vector4(float xAxis, float yAxis, float zAxis, float wComponent);
	Vector4(float axes);
	Vector4(const Vector2& vector);
	Vector4(const Vector3& vector);


	//functions
	float Length() const; 
	float SquaredLength() const; 
	float Normalize();

	//overload operators
	Vector4& operator=(const Vector4& rightSide);
	Vector4	 operator+(const Vector4& rightSide);
	Vector4& operator+=(const Vector4& rightSide);
	Vector4  operator-(const Vector4& rightSide);
	Vector4& operator-=(const Vector4& rightSide);
	Vector4  operator*(const Vector4& rightSide);
	Vector4& operator*=(const Vector4& rightSide);
	Vector4  operator/(const Vector4& rightSide);
	Vector4& operator/=(const Vector4& rightSide);
	bool	 operator==(const Vector4& rightSide);
	bool     operator!=(const Vector4& rightSide);
	friend Vector4 operator*(float unit, const Vector4& rightSide);
	friend Vector4 operator*(const Vector4& leftSide, float unit);
};
