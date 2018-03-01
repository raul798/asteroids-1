#include "Color.hpp"

Color::Color() {

	//Black default color
	redValue = 0.0f;
	greenValue = 0.0f;
	blueValue = 0.0f;
	alphaValue = 1.0f;
}

Color::Color(float red, float green, float blue, float alpha) {

	redValue = red;
	greenValue = green;
	blueValue = blue;
	alphaValue = alpha;
}