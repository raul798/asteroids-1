#include "Player.hpp"

Player::Player() {

	position = new Vector2();
	isThrusterOn = false;
	isInvulnerabilityOn = false;
	shipOrientation = 0.0f;
	//Assign thruster vertex
	PushDrawEntityVertex();
	PushDrawThrusterVertex();
	speed = 0.0f;
	radius = CalculateRadius();
	canPlayerShoot = true;
}

void Player::Update(int screenWidth, int screenHeight, float deltaTime) {

	MathUtilities mathUtilities;

	Entity::Update(screenWidth, screenHeight, deltaTime);
	speed = sqrtf((entityVelocity->x * entityVelocity->x) + (entityVelocity->y * entityVelocity->y));
	
	//if is not moving
	if (!isThrusterOn) {
		
		entityVelocity->x *= coefficientOfFriction;
		entityVelocity->y *= coefficientOfFriction;
	}

	if (speed >= maxSpeed) {

		entityVelocity->x = (entityVelocity->x / speed) * maxSpeed;
		entityVelocity->y = (entityVelocity->y / speed) * maxSpeed;
	}
}

void Player::PushDrawEntityVertex() {

	entityVertexContainer.push_back(Vector2(0.0f, 20.0f));
	entityVertexContainer.push_back(Vector2(12.0f, -10.0f));
	entityVertexContainer.push_back(Vector2(6.0f, -4.0f));
	entityVertexContainer.push_back(Vector2(-6.0f, -4.0f));
	entityVertexContainer.push_back(Vector2(-12.0f, -10.0f));
}

void Player::Render(){

	if (isRendering == true) {



		glLoadIdentity();
		glTranslatef(position->x, position->y, 0.0f);
		glRotatef(shipOrientation, 0.0f, 0.0f, 1.0f);

		if (isInvulnerabilityOn == true) {

			DrawPlayerInvulnerability();
		}
		else {

			DrawEntity();
		}
		
		DrawThruster();
		EntityDebugger();
	}
}

void Player::DrawThruster() {

	if (isThrusterOn == true) {

		glBegin(GL_LINE_LOOP);

		glColor3f(1.0f, 1.0, 1.0f);

		for (int i = 0; i < thrusterVertexContainer.size(); i++) {
			glVertex2f(thrusterVertexContainer[i].x, thrusterVertexContainer[i].y);
		}

		glEnd();
	}
}

void Player::PushDrawThrusterVertex() {

	thrusterVertexContainer.push_back(Vector2(-5.0f, -4.0f));
	thrusterVertexContainer.push_back(Vector2(5.0f, -4.0f));
	thrusterVertexContainer.push_back(Vector2(0.0f, -15.0f));
}

void Player::RotateLeft() {
	
	shipOrientation += rotationValue;
}

void Player::RotateRight() {

	shipOrientation -= rotationValue;
}

//thruster setter
void Player::SetIsThrusterOn(bool thrusterMode){
	isThrusterOn = thrusterMode;
}

void Player::Impulse() {

	MathUtilities mathUtilities;

	entityVelocity->x += (moveForwardValue / mass) * -sinf(mathUtilities.degreesToRadians(shipOrientation));
	entityVelocity->y += (moveForwardValue / mass) * cosf(mathUtilities.degreesToRadians(shipOrientation));
}

void Player::RespawnShip() {

	isRendering = true;
	position = new Vector2(0.0f, 0.0f);
}

float Player::GetShipAngle() {

	return shipOrientation;
}

bool Player::GetIsInvulnerabilityOn() {

	return isInvulnerabilityOn;
}

void Player::SetIsInvulnerabilityOn(bool desiredValue) {


	isInvulnerabilityOn = desiredValue;
}

void Player::DrawPlayerLives() {

	glBegin(GL_LINE_LOOP);

	glColor3f(1.0f, 1.0, 1.0f);

	for (int i = 0; i < entityVertexContainer.size(); i++) {
		glVertex2f(entityVertexContainer[i].x * 0.6f, entityVertexContainer[i].y * 0.6f);
	}

	glEnd();
}

bool Player::GetCanPlayerShoot() {

	return canPlayerShoot;
}

void Player::SetCanPlayerShoot(bool desiredValue) {

	canPlayerShoot = desiredValue;
}
void Player::DrawPlayerInvulnerability() {

	glBegin(GL_LINE_LOOP);

	//green color
	glColor3f(0.48f, 1.0, 0.0f);

	for (int i = 0; i < entityVertexContainer.size(); i++) {
		glVertex2f(entityVertexContainer[i].x, entityVertexContainer[i].y);
	}

	glEnd();
}