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

void Game::UpdateAsteroids(int screenWidth, int screenHeight, float deltaTime) {

	DetermineDebuggerState();
	
	for (int i = 0; i < asteroids.size(); i++) {

		asteroids[i]->Update(screenWidth, screenHeight, deltaTime);
	}
}

void Game::RenderAsteroids() {

	ShowCollisionLines();

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
void Game::SwitchingDebuggerMode() {

	player->ChangeDebuggerState();

	for (int i = 0; i < asteroids.size(); i++) {

		asteroids[i]->ChangeDebuggerState();
	}
}

//Members getters
Player Game::GetPlayer() {

	return *player;
}

std::vector<Asteroid*> Game::GetAsteroids() {

	return asteroids;
}

float Game::GetNumberOfAsteroids() {

	return numberOfAsteroids;
}

void Game::DetermineDebuggerState() {

	if (player->GetDebuggerState() == true) {

		for (int i = 0; i < asteroids.size(); i++) {

			asteroids[i]->SetDebuggerState(true);
		}
	}
}

void Game::ShowCollisionLines() {

	float distanceBetweenEntities;
	float debuggerDetectionRadius = player->GetEntityRadius() * 2;
	
	glLoadIdentity();

	glBegin(GL_LINE_LOOP);

			if (player->GetDebuggerState() == true) {

					for (int i = 0; i < asteroids.size(); i++) {

						// sqrt( (x2 - x1)^2 + (y2 - y1)^2 )
						distanceBetweenEntities =
							sqrt(((player->GetPosition().x - asteroids[i]->GetPosition().x) * (player->GetPosition().x - asteroids[i]->GetPosition().x)) +
							    ((player->GetPosition().y - asteroids[i]->GetPosition().y) * (player->GetPosition().y - asteroids[i]->GetPosition().y)));

						//Distcance between entities <= detection radius(2 * radius) + radius of the asteroid
						if (distanceBetweenEntities <= debuggerDetectionRadius + asteroids[i]->GetEntityRadius()) {

							glVertex2f(player->GetPosition().x, player->GetPosition().y);
							glVertex2f(asteroids[i]->GetPosition().x, asteroids[i]->GetPosition().y);
						}
					}
			}
		glEnd();
}