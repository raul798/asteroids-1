#pragma once
#include "Vector4.hpp"
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

class Entity {

protected:
	Vector2* position;
	std::vector<Vector2> entityVertexContainer;


public:
	//Constructor
	Entity();

	//Functions
	void Update();
	void Render();
	void DrawEntity();
	void PushDrawEntityVertex();
	void Warping(int screenWidth, int screenHeight);
};