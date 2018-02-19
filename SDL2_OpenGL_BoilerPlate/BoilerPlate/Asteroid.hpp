#pragma once
#include "Entity.hpp"

class Asteroid : public Entity{

private:
	int asteroidSize;

public:

	//Asteroid sizes options
	enum AsteroidSize {
		SMALL_SIZE = 1,
		MEDIUM_SIZE = 2,
		BIG_SIZE = 3,
	};

	//Constructors
	Asteroid();
	Asteroid(AsteroidSize asteroidSizeRatio);

	//Functions
	virtual void Update();
	virtual void PushDrawEntityVertex();
	int GetAsteroidSize();
};