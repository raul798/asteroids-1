#include "Player.hpp"
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>


Player::Player() {
	position = new Vector2();
	isThrusterOn = false;
	shipOrientation = 0.0f;
}

void Player::Update() {
	
}

void Player::DrawShip() {

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINE_LOOP);
	glVertex2f(0.0, 20.0);
	glVertex2f(12.0, -10.0);
	glVertex2f(6.0, -4.0);
	glVertex2f(-6.0, -4.0);
	glVertex2f(-12.0, -10.0);
	glEnd();
}

void Player::Render(){

	glLoadIdentity();
	glTranslatef(position->x, position->y, 0.0f);
	glRotatef(-shipOrientation, 0.0f, 0.0f, 1.0f);

	DrawShip();
	DrawThruster();
}

void Player::Warping(int screenWidth, int screenHeight) {
	
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

void Player::DrawThruster() {

	if (isThrusterOn == true) {
		glBegin(GL_LINE_LOOP);
		glVertex2f(-5.0, -4.0);
		glVertex2f(5.0, -4.0);
		glVertex2f(0.0, -15.0);
		glEnd();
	}
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


