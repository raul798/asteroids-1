#pragma once
#include "Entity.hpp"

class Player : public Entity {

private:
	bool isThrusterOn;
	bool isInvulnerabilityOn;
	bool canPlayerShoot;
	float shipOrientation;
	std::vector<Vector2> thrusterVertexContainer;
	const float rotationValue = 8.0f;
	const float coefficientOfFriction = 0.95f;
	const float moveForwardValue = 15.0f;
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
	float GetShipAngle();
	void RespawnShip();
	bool GetIsInvulnerabilityOn();
	void SetIsInvulnerabilityOn(bool desiredValue);
	void DrawPlayerLives();
	bool GetCanPlayerShoot();
	void SetCanPlayerShoot(bool desiredValue);
	void DrawPlayerInvulnerability();
};
