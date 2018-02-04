#include "Player.hpp"
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>



Player::Player() {
	position = new Vector2();
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
	glVertex2f(50.0, 50.0);
	glVertex2f(50.0, -50.0);
	glVertex2f(-50.0, -50.0);
	glVertex2f(-50.0, 50.0);
	glEnd();

}