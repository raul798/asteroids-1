#pragma once
#include "Player.hpp"
#include "Asteroid.hpp"

class Bullet : public Entity {

private:

public:
	//constructor
	Bullet();

	//funcions
	virtual void Render();
	virtual void Update();
	void BulletMovement();

};