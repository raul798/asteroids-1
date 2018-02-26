#pragma once
#include "Player.hpp"
#include "Asteroid.hpp"
#include "InputManager.hpp"
#include "Bullet.hpp"
#include "SDLEvent.hpp"
#include <ctime>

class Game {

private:
	Player * player;
	std::vector<Asteroid*> asteroids;
	std::vector<Bullet*> bullets;
	float numberOfAsteroids;
	//Limit the amount of inputs
	int inputCounter;
	

public:
	//Constructor and destructor
	InputManager inputManager;
	Game();
	~Game();

	//Functions
	void Update(int screenWidth, int screenHeight, float deltaTime);
	void Render();
	void UpdateAllAsteroids(int screenWidth, int screenHeight, float deltaTime);
	void RenderAsteroids();
	void SpawnAsteroids();
	void AddAsteroid();
	void RemoveAsteroid();
	void RemoveFromMemory();
	void SwitchingDebuggerMode();
	void DetermineDebuggerState();
	bool IsInCollisionRange(float distanceBetweenEntities, float radiusOfEntities);
	void ShowShipCollisionLines();
	float CalculateDistanceBetweenEntities(Vector2 firstEntityPosition, Vector2 secondEntityPosition);
	void CollisionOfTheShip();
	void RespawnPlayer();
	void shootBullet();
	void UpdateAllBullets(int screenWidth, int screenHeight, float deltaTime);
	void RenderBullets();
	void CollisionOfTheBullet();
	void CalculateFrameRate();
	void ShowBulletsCollisionLines();
	

	//Input
	InputManager GetInputManager();
	void InputController();
	void ResetInputCounter();
};