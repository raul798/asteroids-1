#pragma once
#include "Vector3.hpp"

class Player {

private:
	Vector2* position;

public:
	Player();
	void Update();
	void Move(Vector2& unit);
	void Render();
};
