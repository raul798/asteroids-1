#pragma once
#include "Player.hpp"
#include "Asteroid.hpp"

class Game {

public:
	Player *player;
	std::vector<Asteroid*> asteroids;
	float numberOfAsteroids;

	//Constructor and destructor
	Game();
	~Game();

	//Functions
	void Update(int screenWidth, int screenHeight, float deltaTime);
	void Render();
	void UpdateAsteroids(int screenWidth, int screenHeight, float deltaTime);
	void RenderAsteroids();
	void SpawnAsteroids();
	void AddAsteroid();
	void RemoveAsteroid();
	void RemoveFromMemory();
	void SwitchingDebuggerMode();
	void determineDebuggerState();
	//void ShowCollisionLines();

	//Members getters
	Player getPlayer();
	std::vector<Asteroid*> getAsteroids();
	float getNumberOfAsteroids();
};