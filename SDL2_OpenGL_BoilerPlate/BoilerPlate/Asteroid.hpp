#pragma once
#include "Entity.hpp"

class Asteroid : public Entity{

private:
	int asteroidSize;
	int asteroidOrientation;
	float asteroidRotationAngle;
	const float asteroidMovementSpeed = 100.0f;
	const float asteroidRotationValue = 35.0f;

public:

	//Asteroid sizes options
	enum AsteroidSize {
		SMALL_SIZE = 3,
		MEDIUM_SIZE = 2,
		BIG_SIZE = 1,
	};

	//Constructors
	Asteroid();
	Asteroid(int asteroidSizeRatio);
	Asteroid(int asteroidSizeRatio, Vector2 desiredPosition);

	//Functions
	virtual void Update(int screenWidth, int screenHeight, float deltaTime);
	virtual void PushDrawEntityVertex();
	virtual void Render();
	int GetAsteroidSize();
	void AsteroidMovement();
	void CalculateRandomOrientation();
};