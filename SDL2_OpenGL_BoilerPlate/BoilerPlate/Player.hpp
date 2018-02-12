#pragma once
#include "Vector4.hpp"

class Player {

private:
	Vector2* position;
	bool isThrusterOn;

public:
	//Constructor
	Player();

	//Functions
	void Update();
	void Move(Vector2& vectorUnit, int screenWidth, int screenHeight);
	void Render();
	void Warping(int screenWidth, int screenHeight);
	void Thruster();
	void MoveFroward();
	void RotateLeft();
	void RotateRight();
	
	//thruster setter
	void setIsThrusterOn(bool thrusterMode);
};
