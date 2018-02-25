#include "Game.hpp"

Game::Game() {

	player = new Player();
	numberOfAsteroids = 5.0f;
	asteroids = std::vector<Asteroid*>(numberOfAsteroids);
	SpawnAsteroids();
}

Game::~Game(){

	RemoveFromMemory();
}

void Game::Update(int screenWidth, int screenHeight, float deltaTime) {

	player->Update(screenWidth, screenHeight, deltaTime);
	UpdateAsteroids(screenWidth, screenHeight, deltaTime);
}

void Game::Render() {

	player->Render();
	RenderAsteroids();
}

void Game::changeDebuggerState() {

}

void Game::UpdateAsteroids(int screenWidth, int screenHeight, float deltaTime) {

	for (int i = 0; i < asteroids.size(); i++) {

		asteroids[i]->Update(screenWidth, screenHeight, deltaTime);
	}
}

void Game::RenderAsteroids() {

	for (int i = 0; i < asteroids.size(); i++) {

		asteroids[i]->Render();
	}
}

void Game::SpawnAsteroids() {

	for (int i = 0; i < asteroids.size(); i++) {

		asteroids[i] = new Asteroid();
	}
}

void Game::AddAsteroid() {

	asteroids.push_back(new Asteroid());
	numberOfAsteroids = asteroids.size();
}

void Game::RemoveAsteroid() {

	if (numberOfAsteroids < 1) {

		std::cout << "can't remove more asteroids" << std::endl;
	}
	else {

		asteroids.pop_back();
		numberOfAsteroids = asteroids.size();
	}

}

void Game::RemoveFromMemory() {

	for (Asteroid* i : asteroids)
	{
		delete i;
	}

	delete player;

}

//activate and desactivate player and asteroids debugging mode
void Game::SwitchgingMode() {

	player->changeDebuggerState();

	for (int i = 0; i < asteroids.size(); i++) {

		asteroids[i]->changeDebuggerState();
	}
}

//Members getters
Player Game::getPlayer() {

	return *player;
}

std::vector<Asteroid*> Game::getAsteroids() {

	return asteroids;
}

float Game::getNumberOfAsteroids() {

	return numberOfAsteroids;
}