#include "Entity.hpp"

Entity::Entity() {

	position = new Vector2();
	mass = 1.0f;
	entityVelocity = new Vector2(0.0f, 0.0f);
	debuggerState = false;

}

void Entity::Update(int screenWidth, int screenHeight, float deltaTime) {
	
	position->x += entityVelocity->x * deltaTime;
	position->y += entityVelocity->y * deltaTime;

	Warping(screenWidth, screenHeight);
}

void Entity::Render() {
	
	glLoadIdentity();
	glTranslatef(position->x, position->y, 0.0f);
	
	DrawEntity();
}

void Entity::DrawEntity() {

	glBegin(GL_LINE_LOOP);

	for (int i = 0; i < entityVertexContainer.size(); i++) {
		glVertex2f(entityVertexContainer[i].x, entityVertexContainer[i].y);
	}

	glEnd();
}

void Entity::PushDrawEntityVertex() {
	//Depends on the object
}

void Entity::Warping(int screenWidth, int screenHeight) {

	int width = screenWidth / 2;
	int height = screenHeight / 2;

	//Evaluating x
	if (position->x < -width) {

		position->x = width;
	}
	else if (position->x > width) {

		position->x = -width;
	}

	//Evaluationg y
	if (position->y < -height) {

		position->y = height;
	}
	else if (position->y > height) {

		position->y = -height;
	}
}

float Entity::CalculateRadius() {
	
	float farthestAxis = 0;

	for (int i = 0; i < entityVertexContainer.size(); i++) {

		if (fabsf(entityVertexContainer[i].x) > farthestAxis) {
		
			farthestAxis = fabsf(entityVertexContainer[i].x);
		}
		
		if (fabsf(entityVertexContainer[i].y) > farthestAxis) {

			farthestAxis = fabsf(entityVertexContainer[i].y);
		}
	}

	return farthestAxis;
}

void Entity::EntityDebugger() {

	if (debuggerState == true) {

		DrawHitCircle();
	}
}

void Entity::DrawHitCircle() {

	MathUtilities mathUtilities;

	int lineAmount = 100;

	float twicePi = 2.0f * mathUtilities.PI;

	glLoadIdentity();

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= lineAmount; i++) {
		glVertex2f(
			position->x + (radius * cos(i * twicePi / lineAmount)),
			position->y + (radius * sin(i * twicePi / lineAmount))
		);
	}
	glEnd();
	
}

void Entity::changeDebuggerState() {
	
	if(debuggerState == false) {

		debuggerState = true;
	}
	else {

		debuggerState = false;
	}
}

