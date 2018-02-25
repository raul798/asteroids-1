#pragma once
#include "Vector4.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

class Entity {

protected:
	Vector2* position;
	std::vector<Vector2> entityVertexContainer;
	Vector2* entityVelocity;
	float mass;
	float speed;
	float radius;
	bool debuggerState;


public:
	//Constructor
	Entity();

	//Functions
	void Update(int screenWidth, int screenHeight, float deltaTime);
	void Render();
	void DrawEntity();
	void PushDrawEntityVertex();
	void Warping(int screenWidth, int screenHeight);
	float CalculateRadius();
	void EntityDebugger();
	void DrawHitCircle();
	void changeDebuggerState();
};