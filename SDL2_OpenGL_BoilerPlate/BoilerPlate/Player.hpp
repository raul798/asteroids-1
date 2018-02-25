#pragma once
#include "Entity.hpp"

class Player : public Entity {

private:
	bool isThrusterOn;
	float shipOrientation;
	std::vector<Vector2> thrusterVertexContainer;
	const float rotationValue = 20.0f;
	const float coefficientOfFriction = 0.95f;
	const float moveForwardValue = 20.0f;
	const float maxSpeed = 300.0f;

public:
	//Constructor
	Player();

	//Functions
	virtual void Update(int screenWidth, int screenHeight, float deltaTime);
	virtual void PushDrawEntityVertex();
	virtual void Render();
	virtual void Impulse();
	void DrawThruster();
	void PushDrawThrusterVertex();
	void RotateLeft();
	void RotateRight();
	void SetIsThrusterOn(bool thrusterMode);
};
