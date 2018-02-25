#pragma once
#include "Player.hpp"
#include "Asteroid.hpp"

class Bullet : public Entity {

private:
	float bulletAngle;

public:
	//constructor
	Bullet(Player playerShip);

	//funcions
	virtual void Render();
	virtual void Update(int screenWidth, int screenHeight, float deltaTime);
	virtual void PushDrawEntityVertex();
	virtual void DrawEntity();
	void BulletMovement();
	void CalculateBulletAngle(Vector2 playerShipPosition);
	void CalculateBulletPosition(float distanceCenterToTip);
};