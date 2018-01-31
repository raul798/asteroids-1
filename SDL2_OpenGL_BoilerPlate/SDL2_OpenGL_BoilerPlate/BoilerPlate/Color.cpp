#include "Color.hpp"

Color::Color() {
	//Black 
	setRed(0.0f);
	setGreen(0.0f);
	setBlue(0.0f);
	setAlpha(1.0f);
}

Color::Color(float redValue, float greenValue, float blueValue, float alphaValue) {
	setRed(redValue);
	setGreen(greenValue);
	setBlue(blueValue);
	setAlpha(alphaValue);
}

void Color::setRed(float red) {
	redValue = red;
}

void Color::setGreen(float green) {
	greenValue = green;
}

void Color::setBlue(float blue) {
	blueValue = blue;
}

void Color::setAlpha(float alpha) {
	alphaValue = alpha;
}

float Color::getRed() {
	return redValue;
}

float Color::getGreen() {
	return greenValue;
}

float Color::getBlue() {
	return blueValue;
}

float Color::getAlpha() {
	return alphaValue;
}