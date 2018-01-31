#pragma once

class Color {

private:
	float redValue;
	float greenValue;
	float blueValue;
	float alphaValue;

public:
	Color();
	Color(float redValue, float greenValue, float blueValue, float alphaValue);

	void setRed(float red);
	void setGreen(float green);
	void setBlue(float blue);
	void setAlpha(float alpha);

	float getRed();
	float getGreen();
	float getBlue();
	float getAlpha();

};