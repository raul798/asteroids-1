#include "Entity.hpp"

Entity::Entity() {

	position = new Vector2();
}

void Entity::Update() {}

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
