#include "Player.hpp"
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>



Player::Player() {
	position = new Vector2();
	isThrusterOn = false;
}

void Player::Update() {}

void Player::Move(Vector2& unit) {
	position->x += unit.x;
	position->y += unit.y;
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

}

void Player::Thruster() {

	//glTranslatef(position->x, position->y, 0.0f);
	if (isThrusterOn) {
		glBegin(GL_LINE_LOOP);
		glVertex2f(-5.0, -4.0);
		glVertex2f(5.0, -4.0);
		glVertex2f(0.0, -15.0);
		glEnd();
	}
}