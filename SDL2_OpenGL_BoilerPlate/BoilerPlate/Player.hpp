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
	void Move(Vector2& unit);
	void Render();
	void Warping();
	void Thruster();
	void MoveFroward();
	void RotateLeft();
	void RotateRight();
	
	//thruster setter
	void setIsThrusterOn(bool thrusterMode);
};
