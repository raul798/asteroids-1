#include "Player.hpp"

Player::Player() {

	isThrusterOn = false;
	shipOrientation = 0.0f;
	mass = 1.0f;
	//Assign thruster vertex
	PushDrawEntityVertex();
	PushDrawThrusterVertex();
}

void Player::Update() {}


void Player::PushDrawEntityVertex() {

	entityVertexContainer.push_back(Vector2(0.0f, 20.0f));
	entityVertexContainer.push_back(Vector2(12.0f, -10.0f));
	entityVertexContainer.push_back(Vector2(6.0f, -4.0f));
	entityVertexContainer.push_back(Vector2(-6.0f, -4.0f));
	entityVertexContainer.push_back(Vector2(-12.0f, -10.0f));
}

void Player::Render(){

	glLoadIdentity();
	glTranslatef(position->x, position->y, 0.0f);
	glRotatef(-shipOrientation, 0.0f, 0.0f, 1.0f);

	DrawEntity();
	DrawThruster();
}


void Player::DrawThruster() {

	if (isThrusterOn == true) {
		glBegin(GL_LINE_LOOP);

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

void Player::MoveFroward(int screenWidth, int screenHeight) {

	MathUtilities mathUtilities;
	float xAxis, yAxis;

	xAxis = moveForwardValue * sinf(mathUtilities.degreesToRadians(shipOrientation));
	yAxis = moveForwardValue * cosf(mathUtilities.degreesToRadians(shipOrientation));

	position->x += xAxis;
	position->y += yAxis;

	Warping(screenWidth, screenHeight);
}

void Player::RotateLeft() {
	
	shipOrientation -= rotationValue;
}

void Player::RotateRight() {

	shipOrientation += rotationValue;
}

//thruster setter
void Player::setIsThrusterOn(bool thrusterMode){
	isThrusterOn = thrusterMode;
}


