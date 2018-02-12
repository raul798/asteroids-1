#include "Player.hpp"
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

//const int screenWidth = 568;
//const int screenHeight = 320;

Player::Player() {
	position = new Vector2();
	isThrusterOn = false;
}

void Player::Update() {}

void Player::Move(Vector2& vectorUnit, int screenWidth, int screenHeight) {
	position->x += vectorUnit.x;
	position->y += vectorUnit.y;

	Warping(screenWidth, screenHeight);
}

void Player::Render(){

	glLoadIdentity();

	glTranslatef(position->x, position->y, 0.0f);

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINE_LOOP);
	glVertex2f(0.0, 20.0);
	glVertex2f(12.0, -10.0);
	glVertex2f(6.0, -4.0);
	glVertex2f(-6.0, -4.0);
	glVertex2f(-12.0, -10.0);
	glEnd();

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

void Player::Thruster() {

	if (isThrusterOn == true) {
		glBegin(GL_LINE_LOOP);
		glVertex2f(-5.0, -4.0);
		glVertex2f(5.0, -4.0);
		glVertex2f(0.0, -15.0);
		glEnd();
	}
}

void Player::MoveFroward() {}

void Player::RotateLeft() {}

void Player::RotateRight() {}

//thruster setter
void Player::setIsThrusterOn(bool thrusterMode){
	isThrusterOn = thrusterMode;
}

