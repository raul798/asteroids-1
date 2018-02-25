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
	UpdateAllAsteroids(screenWidth, screenHeight, deltaTime);
	UpdateAllBullets(screenWidth, screenHeight, deltaTime);
}

void Game::Render() {

	player->Render();
	RenderAsteroids();
	RenderBullets();
}

void Game::UpdateAllAsteroids(int screenWidth, int screenHeight, float deltaTime) {

	DetermineDebuggerState();
	CollisionOfTheShip();
	
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

		std::cout << "Can't remove more asteroids" << std::endl;
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

void Game::DetermineDebuggerState() {

	if (player->GetDebuggerState() == true) {

		for (int i = 0; i < asteroids.size(); i++) {

			asteroids[i]->SetDebuggerState(true);
		}
	}
}

float Game::CalculateDistanceBetweenEntities(Vector2 firstEntityPosition, Vector2 secondEntityPosition) {

	float distanceBetweenEntities;

	// sqrt( (x2 - x1)^2 + (y2 - y1)^2 )
	distanceBetweenEntities =
		sqrt(((firstEntityPosition.x - secondEntityPosition.x) * (firstEntityPosition.x - secondEntityPosition.x)) +
		((firstEntityPosition.y - secondEntityPosition.y) * (firstEntityPosition.y - secondEntityPosition.y)));

	return distanceBetweenEntities;
}

bool Game::IsInCollisionRange(float distanceBetweenEntities, float radiusOfEntities) {

	if (distanceBetweenEntities <= radiusOfEntities) {

		return true;
	}
	else {

		return false;
	}

}

void Game::ShowCollisionLines() {

	float distanceBetweenEntities;
	float debuggerDetectionRadius = player->GetEntityRadius() * 2;
	
	glLoadIdentity();

	glBegin(GL_LINE_LOOP);

	//white color
	glColor3f(1.0f, 1.0, 1.0f);

			if (player->GetDebuggerState() == true) {

					for (int i = 0; i < asteroids.size(); i++) {

						// sqrt( (x2 - x1)^2 + (y2 - y1)^2 )
						distanceBetweenEntities = CalculateDistanceBetweenEntities( player->GetPosition(), asteroids[i]->GetPosition() );

						//Distcance between entities <= detection radius(2 * radius) + radius of the asteroid
						if (IsInCollisionRange(distanceBetweenEntities, debuggerDetectionRadius + asteroids[i]->GetEntityRadius())) {

							//validate if the player is rendering(dead or alive) so it doesnt or does show the lines of the debugger
							if (player->GetIsRendering() == true) {

								//if is in collision range
								if (IsInCollisionRange(distanceBetweenEntities, player->GetEntityRadius() + asteroids[i]->GetEntityRadius())) {

									//change line color to red
									glColor3f(1.0f, 0.0, 0.0f);

									glVertex2f(player->GetPosition().x, player->GetPosition().y);
									glVertex2f(asteroids[i]->GetPosition().x, asteroids[i]->GetPosition().y);
								}
								else {

									//go back to white
									glColor3f(1.0f, 1.0, 1.0f);

									glVertex2f(player->GetPosition().x, player->GetPosition().y);
									glVertex2f(asteroids[i]->GetPosition().x, asteroids[i]->GetPosition().y);
								}

							}
						}
					}
			}
		glEnd();
}

void Game::CollisionOfTheShip() {

	float distanceBetweenEntities;

	if (player->GetDebuggerState() == false) {

		for (int i = 0; i < asteroids.size(); i++) {

			distanceBetweenEntities = CalculateDistanceBetweenEntities(player->GetPosition(), asteroids[i]->GetPosition());

			if (IsInCollisionRange(distanceBetweenEntities, player->GetEntityRadius() + asteroids[i]->GetEntityRadius())) {

				player->SetIsRendering(false);
			}
		}
	}
}

void Game::RespawnPlayer() {

	player->RespawnShip();
}

void Game::OnKeyDown(SDL_KeyboardEvent keyBoardEvent)
{
	switch (keyBoardEvent.keysym.scancode)
	{
	case SDL_SCANCODE_W:
		SDL_Log("Up");
		player->Impulse();
		player->SetIsThrusterOn(true);
		break;

	case SDL_SCANCODE_A:
		SDL_Log("Left");
		player->RotateLeft();
		break;

	case SDL_SCANCODE_D:
		SDL_Log("Right");
		player->RotateRight();
		break;

	case SDL_SCANCODE_S:
		SDL_Log("Down");
		break;

	case SDL_SCANCODE_R:
		SDL_Log("Remove Asteroid");
		RemoveAsteroid();
		break;

	case SDL_SCANCODE_T:
		SDL_Log("Add Asteroid");
		AddAsteroid();
		break;

	case SDL_SCANCODE_G:
		SDL_Log("Debugger Mode");
		SwitchingDebuggerMode();
		break;

	case SDL_SCANCODE_Y:
		SDL_Log("Respawn Player");
		RespawnPlayer();
		break;

	case SDL_SCANCODE_SPACE:
		SDL_Log("Shoot");
		shootBullet();
		break;

	default:
		SDL_Log("%S was pressed.", keyBoardEvent.keysym.scancode);
		break;
	}
}

void Game::OnKeyUp(SDL_KeyboardEvent keyBoardEvent)
{
	switch (keyBoardEvent.keysym.scancode)
	{
	case SDL_SCANCODE_W:
		player->SetIsThrusterOn(false);
		break;

	default:
		break;
	}
}

void Game::UpdateAllBullets(int screenWidth, int screenHeight, float deltaTime) {

	CollisionOfTheBullet();

	for (int i = 0; i < bullets.size(); i++) {
	
		bullets[i]->Update(screenWidth, screenHeight, deltaTime);
	}
}

void Game::RenderBullets() {

	for (int i = 0; i < bullets.size(); i++) {

		bullets[i]->Render();
	}
}

void Game::shootBullet() {

	//check if is alive
	if (player->GetIsRendering() == true) {

		bullets.push_back(new Bullet(*player));
	}
	
}

void Game::CollisionOfTheBullet(){

	float distanceBetweenEntities;

	if (player->GetDebuggerState() == false) {

		for (int i = 0; i < bullets.size(); i++) {

			for (int j = 0; j < asteroids.size(); j++) {

				distanceBetweenEntities = CalculateDistanceBetweenEntities(bullets[i]->GetPosition(), asteroids[j]->GetPosition());
	
				if (IsInCollisionRange(distanceBetweenEntities, bullets[i]->GetEntityRadius() + asteroids[j]->GetEntityRadius())) {

					//remove the asteroid and the bullet on impact
					bullets[i]->SetIsRendering(false);
					asteroids[j]->SetIsRendering(false);
					asteroids.erase(asteroids.begin() + j);
					bullets.erase(bullets.begin() + i);
					break;
				}
			}
		}
	}
}