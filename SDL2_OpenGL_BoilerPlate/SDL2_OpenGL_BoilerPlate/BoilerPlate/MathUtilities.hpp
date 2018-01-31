#pragma once

class MathUtilities {

public:
	int floatToInt(float number);
	int floatToEvenInt(float number);
	float degreesToRadians(float degree);
	float radiansToDegrees(float radian);
	float angularDistance(float angleA, float angleB);
	float interpolate(float startValue, float endValue, float fraction);
	bool intPowerOfTwo(int number);

	template <class type> type getMax(type a, type b) {
		type result;

		if (a >= b) {
			result = a;
		}
		else {
			result = b;
		}

		return result;
	}

	template <class type> type getMax(type a, type b, type c) {
		type result, firstMax;

		firstMax = getMax(a, b);
		result = getMax(firstMax, c);

		return result;
	}

	template <class type> type getMax(type a, type b, type c, type d) {
		type result, firstMax;

		firstMax = getMax(a, b, c);
		result = getMax(firstMax, d);

		return result;
	}

	template <class type> type getMin(type a, type b) {
		type result;

		if (a <= b) {
			result = a;
		}
		else {
			result = b;
		}

		return result;
	}

	template <class type> type getMin(type a, type b, type c) {
		type result, firstMin;

		firstMin = getMin(a, b);
		result = getMin(firstMin, c);

		return result;
	}

	template <class type> type getMin(type a, type b, type c, type d) {
		type result, firstMin;

		firstMin = getMin(a, b, c);
		result = getMin(firstMin, d);

		return result;
	}

	template <class type> type clamp(type number, type min, type max) {

		if (number < min) {
			number = min;
		}
		else if (number > max) {
			number = max;
		}

		return number;
	}
};