#pragma once
#include "Vector2.hpp"

struct Vector3 {

	//members
	float x;
	float y;
	float z;
	float length;

	//constructors
	Vector3();
	Vector3(float xAxis, float yAxis, float zAxis);
	Vector3(float axes);
	Vector3(const Vector2& vector);


	//functions
	float Length() const; //const
	float SquaredLength() const; //const
	float Normalize();

	//overload operators
	Vector3& operator=(const Vector3& rightSide);
	Vector3	 operator+(const Vector3& rightSide);
	Vector3& operator+=(const Vector3& rightSide);
	Vector3  operator-(const Vector3& rightSide);
	Vector3& operator-=(const Vector3& rightSide);
	Vector3  operator*(const Vector3& rightSide);
	Vector3& operator*=(const Vector3& rightSide);
	Vector3  operator/(const Vector3& rightSide);
	Vector3& operator/=(const Vector3& rightSide);
	bool	 operator==(const Vector3& rightSide);
	bool     operator!=(const Vector3& rightSide);
	friend Vector3 operator*(float unit, const Vector3& rightSide);
	friend Vector3 operator*(const Vector3& leftSide, float unit);
};
