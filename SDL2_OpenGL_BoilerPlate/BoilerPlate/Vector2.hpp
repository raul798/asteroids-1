#pragma once
#include "cmath"
#include "MathUtilities.hpp"

struct Vector2 {

	//members
	float x;
	float y;
	float length;

	//constructors
	Vector2();
	Vector2(float xAxes, float yAxes);
	Vector2(float Axes);

	//functions
	float Length() const ; //const
	float SquaredLength() const ; //const
	float Normalize();

	//overload operators
	Vector2& operator=(const Vector2& rightSide);
	Vector2	 operator+(const Vector2& rightSide);
	Vector2& operator+=(const Vector2& rightSide);
	Vector2  operator-(const Vector2& rightSide);
	Vector2& operator-=(const Vector2& rightSide);
	Vector2  operator*(const Vector2& rightSide);
	Vector2& operator*=(const Vector2& rightSide);
	Vector2  operator/(const Vector2& rightSide);
	Vector2& operator/=(const Vector2& rightSide);
	bool	 operator==(const Vector2& rightSide);
	bool     operator!=(const Vector2& rightSide);
	friend Vector2 operator*(float unit, const Vector2& rightSide);
	friend Vector2 operator*(const Vector2& leftSide, float unit);
};