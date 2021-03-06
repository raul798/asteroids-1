#pragma once
#include "Vector4.hpp"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "includeSDL.hpp"

class Entity {

protected:
	Vector2* position;
	std::vector<Vector2> entityVertexContainer;
	Vector2* entityVelocity;
	float mass;
	float speed;
	float radius;
	bool debuggerState;
	bool isRendering;


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
	void DrawCircleAroundEntity();
	void ChangeDebuggerState();
	bool GetDebuggerState();
	void SetDebuggerState(bool shipDebuggerState);
	Vector2 GetPosition();
	float GetEntityRadius();
	bool GetIsRendering();
	void SetIsRendering(bool desiredValue);
};