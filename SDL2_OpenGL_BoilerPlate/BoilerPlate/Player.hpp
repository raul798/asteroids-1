#pragma once
#include "Entity.hpp"

class Player : public Entity {

private:
	bool isThrusterOn;
	float shipOrientation;
	std::vector<Vector2> thrusterVertexContainer;
	float mass;
	const float rotationValue = 20.0f;
	const float moveForwardValue = 5.0f;

public:
	//Constructor
	Player();

	//Functions
	virtual void Update();
	virtual void PushDrawEntityVertex();
	virtual void Render();
	void DrawThruster();
	void PushDrawThrusterVertex();
	void MoveFroward(int screenWidth, int screenHeight);
	void RotateLeft();
	void RotateRight();
	
	//thruster setter
	void setIsThrusterOn(bool thrusterMode);
};
