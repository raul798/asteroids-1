#pragma once
#include "Player.hpp"
#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "SDLEvent.hpp"
#include <ctime>

class Game {

public:
	Player * player;
	std::vector<Asteroid*> asteroids;
	std::vector<Bullet*> bullets;
	float numberOfAsteroids;

	//Constructor and destructor
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
	void OnKeyDown(SDL_KeyboardEvent keyBoardEvent);
	void OnKeyUp(SDL_KeyboardEvent keyBoardEvent);
};