#pragma once
#include "Vector4.hpp"

class Player {

private:
	Vector2* position;

public:
	//Public members
	bool isThrusterOn;

	//Constructor
	Player();

	//Functions
	void Update();
	void Move(Vector2& unit);
	void Render();
	void Warping();
	void Thruster();
	
};
