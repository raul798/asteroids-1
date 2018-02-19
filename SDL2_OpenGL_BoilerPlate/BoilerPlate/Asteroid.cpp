#include "Asteroid.hpp"

Asteroid::Asteroid() {
	
	//small size default
	asteroidSize = 1;
	PushDrawEntityVertex();
}

Asteroid::Asteroid(AsteroidSize asteroidSizeRatio) {

	asteroidSize = asteroidSizeRatio;
	PushDrawEntityVertex();
}

void Asteroid::Update() {}

int Asteroid::GetAsteroidSize() {
	return asteroidSize;
}

void Asteroid::PushDrawEntityVertex() {

	int asteroidSizeRatio = GetAsteroidSize() ;

	entityVertexContainer.push_back(Vector2(0.0f * asteroidSizeRatio, 20.0f * asteroidSizeRatio));
	entityVertexContainer.push_back(Vector2(10.0f * asteroidSizeRatio, 17.0f *asteroidSizeRatio));
	entityVertexContainer.push_back(Vector2(15.0f * asteroidSizeRatio, 15.0f * asteroidSizeRatio));
	entityVertexContainer.push_back(Vector2(14.0f * asteroidSizeRatio, 11.5f * asteroidSizeRatio));
	entityVertexContainer.push_back(Vector2(16.5f * asteroidSizeRatio, 9.0f * asteroidSizeRatio));
	entityVertexContainer.push_back(Vector2(20.0f * asteroidSizeRatio, 2.0f * asteroidSizeRatio));
	entityVertexContainer.push_back(Vector2(12.0f * asteroidSizeRatio, -5.0f * asteroidSizeRatio));
	entityVertexContainer.push_back(Vector2(13.5f * asteroidSizeRatio, -12.0f * asteroidSizeRatio));
	entityVertexContainer.push_back(Vector2(8.5f * asteroidSizeRatio, -15.0f * asteroidSizeRatio));
	entityVertexContainer.push_back(Vector2(5.0f * asteroidSizeRatio, -14.0f * asteroidSizeRatio));
	entityVertexContainer.push_back(Vector2(2.5f * asteroidSizeRatio, -20.0f * asteroidSizeRatio));
	entityVertexContainer.push_back(Vector2(-3.5f * asteroidSizeRatio, -20.0f * asteroidSizeRatio));
	entityVertexContainer.push_back(Vector2(-10.0f * asteroidSizeRatio, -17.5f * asteroidSizeRatio));
	entityVertexContainer.push_back(Vector2(-15.0f * asteroidSizeRatio, -19.0f * asteroidSizeRatio));
	entityVertexContainer.push_back(Vector2(-20.0f * asteroidSizeRatio, -7.5f * asteroidSizeRatio));
	entityVertexContainer.push_back(Vector2(-19.0f * asteroidSizeRatio, 0.0f * asteroidSizeRatio));
	entityVertexContainer.push_back(Vector2(-15.0f * asteroidSizeRatio, 7.5f * asteroidSizeRatio));
	entityVertexContainer.push_back(Vector2(-12.5f * asteroidSizeRatio, 14.5f * asteroidSizeRatio));
	entityVertexContainer.push_back(Vector2(-5.0f * asteroidSizeRatio, 15.0f * asteroidSizeRatio));
}

