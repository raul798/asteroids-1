#include "Player.hpp"
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

const int screenWidth = 568;
const int screenHeight = 320;

Player::Player() {
	position = new Vector2();
	isThrusterOn = false;
}

void Player::Update() {}

void Player::Move(Vector2& unit) {
	position->x += unit.x;
	position->y += unit.y;

	Warping();
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

void Player::Warping() {
	
	//Evaluating x
	if (position->x < -screenWidth) {
		position->x = screenWidth;
	}
	else if (position->x > screenWidth) {
		position->x = -screenWidth;
	}

	//Evaluationg y
	if (position->y < -screenHeight) {
		position->y = screenHeight;
	}
	else if (position->y > screenHeight) {
		position->y = -screenHeight;
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

