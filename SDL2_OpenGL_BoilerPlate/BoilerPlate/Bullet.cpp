#include "Bullet.hpp"

Bullet::Bullet(Player playerShip) {

	speed = 400.0f;
	bulletAngle = playerShip.GetShipAngle();
	CalculateBulletPosition(playerShip);
	radius = CalculateRadius();
}

void Bullet::Render() {

	if (isRendering == true) {

		glLoadIdentity();
		glTranslatef(position->x, position->y, 0.0f);

		DrawEntity();
	}
}

void Bullet::Update(int screenWidth, int screenHeight, float deltaTime) {

	Entity::Update(screenWidth, screenHeight, deltaTime);
	BulletMovement();
}

void Bullet::BulletMovement() {

	MathUtilities mathUtilities;

	entityVelocity->x = (speed / mass) * -sinf(mathUtilities.degreesToRadians(bulletAngle));
	entityVelocity->y = (speed / mass) * cosf(mathUtilities.degreesToRadians(bulletAngle));
}

void Bullet::CalculateBulletPosition(Player playerShip) {

	MathUtilities mathUtilities;

	//xAxis of the bullet = x + ((cos(ship angle) + (distance to the tip of the ship)) * -sin(ship angle))
	position->x = playerShip.GetPosition().x + ((cosf(mathUtilities.degreesToRadians(bulletAngle)) +
		playerShip.GetEntityRadius()) * (-sinf(mathUtilities.degreesToRadians(bulletAngle))));

	//xAxis of the bullet = x + ((-sin(ship angle) + (distance to the tip of the ship)) * cos(ship angle))
	position->y = playerShip.GetPosition().y + ((-sinf(mathUtilities.degreesToRadians(bulletAngle)) +
		playerShip.GetEntityRadius()) * (cosf(mathUtilities.degreesToRadians(bulletAngle))));
}

void Bullet::PushDrawEntityVertex() {

	entityVertexContainer.push_back(Vector2(0.0f, 1.0f));
	entityVertexContainer.push_back(Vector2(1.0f, 1.0f));
	entityVertexContainer.push_back(Vector2(1.0f, 0.0f));
	entityVertexContainer.push_back(Vector2(1.0f, -1.0f));
	entityVertexContainer.push_back(Vector2(0.0f, -1.0f));
	entityVertexContainer.push_back(Vector2(-1.0f, -1.0f));
	entityVertexContainer.push_back(Vector2(-1.0f, 0.0f));
	entityVertexContainer.push_back(Vector2(-1.0f, 1.0f));
}

void Bullet::DrawEntity() {

	glBegin(GL_LINE_LOOP);

	glColor3f(1.0f, 1.0, 1.0f);

	PushDrawEntityVertex();

	for (int i = 0; i < entityVertexContainer.size(); i++) {
		glVertex2f(entityVertexContainer[i].x, entityVertexContainer[i].y);
	}

	glEnd();
}