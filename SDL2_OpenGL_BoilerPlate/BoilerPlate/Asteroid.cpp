#include "Asteroid.hpp"

Asteroid::Asteroid() {
	
	//small size default
	position = new Vector2(rand(), rand());
	asteroidSize = 3;
	asteroidRotationAngle = 0.0f;
	PushDrawEntityVertex();
	CalculateRandomOrientation();
	radius = CalculateRadius();
}

Asteroid::Asteroid(AsteroidSize asteroidSizeRatio) {

	asteroidSize = asteroidSizeRatio;
	asteroidRotationAngle = 0.0f;
	PushDrawEntityVertex();
	CalculateRandomOrientation();
}

void Asteroid::Update(int screenWidth, int screenHeight, float deltaTime) {
	
	Entity::Update(screenWidth, screenHeight, deltaTime);
	AsteroidMovement();

	//changing asteroid rotation angle
	asteroidRotationAngle += asteroidRotationValue * deltaTime;
}

void Asteroid::Render() {

	if (isRendering == true) {

		glLoadIdentity();
		glTranslatef(position->x, position->y, 0.0f);
		glRotatef(asteroidRotationAngle, 0.0f, 0.0f, 1.0f);

		DrawEntity();
		EntityDebugger();
	}
}

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

void Asteroid::CalculateRandomOrientation() {

	asteroidOrientation = rand() % 360;
}

void Asteroid::AsteroidMovement() {

	MathUtilities mathUtilities;

	entityVelocity->x = (asteroidMovementSpeed / mass) * -sinf(mathUtilities.degreesToRadians(asteroidOrientation)) + asteroidSize;
	entityVelocity->y = (asteroidMovementSpeed / mass) * cosf(mathUtilities.degreesToRadians(asteroidOrientation)) + asteroidSize;
}


