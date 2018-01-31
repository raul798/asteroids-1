#include "MathUtilities.hpp"

int MathUtilities::floatToInt(float number) {
	int result;

	if (number >= 0) {
		result = (int)(number + 0.5);
	}
	else {
		result = (int)(number - 0.5);
	}

	return result;
}

int MathUtilities::floatToEvenInt(float number) {
	int result, firstDecimal, intNumber;

	if (number >= 0) {
		intNumber = (int)(number + 0.5);
	}
	else {
		intNumber = (int)(number - 0.5);
	}

	if (result % 2 == 0) {
		result = intNumber;
	}
	else {
		firstDecimal = (int)(number * 10) % 10;
		if (firstDecimal >= 5) {
			result = intNumber + 1;
		}
		else if (firstDecimal < 5) {
			result = intNumber;
		}
	}
	return result;
}

float MathUtilities::degreesToRadians(float degree) {
	float result;

	result = ((degree * 3.141592) / 180);
	return result;
}

float MathUtilities::radiansToDegrees(float radian) {
	float result;

	result = ((radian * 180) / 3.141592);
	return result;
}

float MathUtilities::angularDistance(float angleA, float angleB) {
	float result;

	if (angleA < 0 && angleB > 0) {
		result = (angleA + angleB) * -1;
	}

	else if (angleA < 0 && angleB < 0) {
		result = (angleA - angleB) * -1;
	}

	else if (angleA > 0 && angleB > 0) {
		result = angleA - angleB;
	}

	else if (angleA > 0 && angleB < 0) {
		result = angleA + angleB;
	}

	else if (angleA == 0 && angleB < 0) {
		result = angleA - angleB;
	}

	else if (angleA == 0 && angleB > 0) {
		result = angleA - angleB;
	}

	else if (angleA < 0 && angleB == 0) {
		result = angleA * -1;
	}

	else if (angleA > 0 && angleB == 0) {
		result = angleA;
	}

	return result;
}

float MathUtilities::interpolate(float startValue, float endValue, float fraction) {
	float result;

	result = (fraction * (endValue - startValue)) + startValue;

	return result;
}

bool MathUtilities::intPowerOfTwo(int number) {
	bool result;
	if (number > 0 && ((number & (number - 1)) == 0)) {
		result = true;
	}
	else {
		result = false;
	}

	return result;
}