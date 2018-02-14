#pragma once
#include "Vector4.hpp"

class Player {

private:
	Vector2* position;
	bool isThrusterOn;
	float shipOrientation;
	const float rotationValue = 20.0f;
	const float moveForwardValue = 5.0f;

public:
	//Constructor
	Player();

	//Functions
	void Update();
	void DrawShip();
	void Render();
	void Warping(int screenWidth, int screenHeight);
	void DrawThruster();
	void MoveFroward(int screenWidth, int screenHeight);
	void RotateLeft();
	void RotateRight();
	
	//thruster setter
	void setIsThrusterOn(bool thrusterMode);
};
