#pragma once
#include "Player.hpp"
#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "InputManager.hpp"

const float DESIRED_FRAME_RATE = 60.0f;
const float DESIRED_FRAME_TIME = 1.0f / DESIRED_FRAME_RATE;
const int FRAME_STORAGE_LIMIT = 20;
const float FRAME_RATE_SCALE_Y = 100000.0f;
const float FRAME_RATE_SCALE_X = 10.0f;

class Game {

private:
	Player *player;
	std::vector<Asteroid*> asteroids;
	std::vector<Bullet*> bullets;
	std::vector<Vector2> storageDeltaTime;
	float gameScreenWidth;
	float gameScreenHeight;
	int storageDeltaTimeCounter;
	float numberOfAsteroids;
	const float initialNumberOfAsteroids = 5.0f;
	int stageCounter;
	int playerRemainingLives;
	bool isFrameRateOn;
	const float distanceBetweenLives = -30.0f;
	float invulnerabilityTimeCounter;
	int playerScore;;
	int livesPerScoreCounter;
	const int scoreToGetLife = 3000;
	//Limit the amount of inputs
	int inputCounter;
	
public:
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
	void ShowBulletsCollisionLines();
	void FillStorageDeltaTime();
	void UpdateFrameRate(double endTime, double startTime);
	void GraphFrameRate();
	void DrawGraphAxes();
	void DrawFrameRateGraph();
	void ToggleFramerate();
	float CalculateFrameRate(double endTime, double startTime);
	void DrawPlayerRemainingLives();
	void CheckPlayerInvulnerability();
	void UpdateInputController();
	void UpdateScreenDimensions(int screenWidth, int screenHeight);
	void SpawnAsteroidsPerStage();
	void ResetGame();
	void AdditionalLivesPerScore();

	//Input
	InputManager inputManager;
	InputManager GetInputManager();
	void InputController();
	void ResetInputCounter();
};