#pragma once

#include "Color.hpp"

class ColorPalette {

private:
	Color black = Color(0.0f, 0.0f, 0.0f, 1.0f);
	Color darkSlateGray = Color(0.184f, 0.31f, 0.31f, 1.0f);
	Color maroon = Color(0.502f, 0.0f, 0.0f, 1.0f);
	Color chocolate = Color(0.824f, 0.412f, 0.118f, 1.0f);
	Color midnightBlue = Color(0.098f, 0.098f, 0.439f, 1.0f);

public:
	//getBlack
	float getBlackRedValue();
	float getBlackGreenValue();
	float getBlackBlueValue();
	float getBlackAlphaValue();

	//getDarkSlateGray
	float getDarkSlateGrayRedValue();
	float getDarkSlateGrayGreenValue();
	float getDarkSlateGrayBlueValue();
	float getDarkSlateGrayAlphaValue();

	//getMaroon
	float getMaroonRedValue();
	float getMaroonGreenValue();
	float getMaroonBlueValue();
	float getMaroonAlphaValue();

	//getChocolate
	float getChocolateRedValue();
	float getChocolateGreenValue();
	float getChocolateBlueValue();
	float getChocolateAlphaValue();

	//getMidnightBlue
	float getMidnightBlueRedValue();
	float getMidnightBlueGreenValue();
	float getMidnightBlueBlueValue();
	float getMidnightBlueAlphaValue();



};