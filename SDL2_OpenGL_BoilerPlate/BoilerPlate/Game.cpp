#include "Game.hpp"

Game::Game() {

	player = new Player();
	numberOfAsteroids = 5.0f;
	asteroids = std::vector<Asteroid*>(numberOfAsteroids);
	SpawnAsteroids();
	ResetInputCounter();
}

Game::~Game(){

	RemoveFromMemory();
}

void Game::Update(int screenWidth, int screenHeight, float deltaTime) {

	InputController();

	if (inputCounter > 0) {

		inputCounter--;
	}

	player->Update(screenWidth, screenHeight, deltaTime);
	UpdateAllAsteroids(screenWidth, screenHeight, deltaTime);
	UpdateAllBullets(screenWidth, screenHeight, deltaTime);

	//CalculateFrameRate();
	//TODO: add framrate calculation function
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

	ShowShipCollisionLines();

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

	//can only add asteroids in debugging mode
	if (player->GetDebuggerState() == true) {
		asteroids.push_back(new Asteroid());
		numberOfAsteroids = asteroids.size();
	}
	
}

void Game::RemoveAsteroid() {

	//can only remove asteroids in debugging mode
	if (player->GetDebuggerState() == true) {

		if (numberOfAsteroids < 1) {

			std::cout << "Can't remove more asteroids" << std::endl;
		}
		else {

			asteroids.pop_back();
			numberOfAsteroids = asteroids.size();
		}
	}
}

void Game::RemoveFromMemory() {

	for (Asteroid* i : asteroids)
	{
		delete i;
	}

	for (Bullet* i : bullets)
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

void Game::ShowShipCollisionLines() {

	float distanceBetweenEntities;
	float debuggerDetectionRadius = player->GetEntityRadius() * 2;
	
			if (player->GetDebuggerState() == true) {

					for (int i = 0; i < asteroids.size(); i++) {

						// sqrt( (x2 - x1)^2 + (y2 - y1)^2 )
						distanceBetweenEntities = CalculateDistanceBetweenEntities(player->GetPosition(), asteroids[i]->GetPosition());

						//Distcance between entities <= detection radius(2 * radius) + radius of the asteroid
						if (IsInCollisionRange(distanceBetweenEntities, debuggerDetectionRadius + asteroids[i]->GetEntityRadius())) {

							glLoadIdentity();

							glBegin(GL_LINE_LOOP);

							//white color
							glColor3f(1.0f, 1.0, 1.0f);

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
							glEnd();
						}
					}
			}
		
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

void Game::UpdateAllBullets(int screenWidth, int screenHeight, float deltaTime) {

	CollisionOfTheBullet();
	
	for (int i = 0; i < bullets.size(); i++) {
	
		bullets[i]->Update(screenWidth, screenHeight, deltaTime);

		//the bullet disapear after 1 second
		if (bullets[i]->GetBulletLifeSapwn() >= 1.0f) {

			bullets.erase(bullets.begin() );
			break;
		}
	}
}

void Game::RenderBullets() {

	ShowBulletsCollisionLines();

	for (int i = 0; i < bullets.size(); i++) {

		bullets[i]->Render();
	}
}

void Game::shootBullet() {

	//check if is alive
	if (player->GetIsRendering() == true) {

		//limit the amount of bullets to 4
		if (bullets.size() < 4) {

			bullets.push_back(new Bullet(*player));
		}
	}
}

void Game::CollisionOfTheBullet(){

	float distanceBetweenEntities;

	if (player->GetDebuggerState() == false) {

		for (int i = 0; i < bullets.size(); i++) {

			for (int j = 0; j < asteroids.size(); j++) {

				distanceBetweenEntities = CalculateDistanceBetweenEntities(bullets[i]->GetPosition(), asteroids[j]->GetPosition());
	
				if (IsInCollisionRange(distanceBetweenEntities, bullets[i]->GetEntityRadius() + asteroids[j]->GetEntityRadius())) {

					//divide asteroids depending on size
					if(asteroids[j]->GetAsteroidSize() == 3) {

						asteroids.push_back(new Asteroid(2, asteroids[j]->GetPosition()));
						asteroids.push_back(new Asteroid(2, asteroids[j]->GetPosition()));
					}
					if(asteroids[j]->GetAsteroidSize() == 2) {

						asteroids.push_back(new Asteroid(1, asteroids[j]->GetPosition()));
						asteroids.push_back(new Asteroid(1, asteroids[j]->GetPosition()));
					}
					
					//remove the asteroid and the bullet on impact
					asteroids.erase(asteroids.begin() + j);
					bullets.erase(bullets.begin() + i);
					numberOfAsteroids = asteroids.size();
					break;
				}
			}
		}
	}
}

void Game::ShowBulletsCollisionLines() {

	float distanceBetweenEntities;
	float debuggerDetectionRadius;

	if (player->GetDebuggerState() == true) {

		for (int j = 0; j < bullets.size(); j++) {

			debuggerDetectionRadius = bullets[j]->GetEntityRadius() * 2;

			for (int i = 0; i < asteroids.size(); i++) {

				// sqrt( (x2 - x1)^2 + (y2 - y1)^2 )
				distanceBetweenEntities = CalculateDistanceBetweenEntities(bullets[j]->GetPosition(), asteroids[i]->GetPosition());

				//Distcance between entities <= detection radius(2 * radius) + radius of the asteroid
				if (IsInCollisionRange(distanceBetweenEntities, debuggerDetectionRadius + asteroids[i]->GetEntityRadius())) {

					glLoadIdentity();
					glBegin(GL_LINE_LOOP);

					//white color
					glColor3f(1.0f, 1.0, 1.0f);

					//validate if the player is rendering(dead or alive) so it doesnt or does show the lines of the debugger
					if (player->GetIsRendering() == true) {

						//if is in collision range
						if (IsInCollisionRange(distanceBetweenEntities, bullets[j]->GetEntityRadius() + asteroids[i]->GetEntityRadius())) {

							//change line color to red
							glColor3f(1.0f, 0.0, 0.0f);

							glVertex2f(bullets[j]->GetPosition().x, bullets[j]->GetPosition().y);
							glVertex2f(asteroids[i]->GetPosition().x, asteroids[i]->GetPosition().y);
						}
						else {

							//go back to white
							glColor3f(1.0f, 1.0, 1.0f);

							glVertex2f(bullets[j]->GetPosition().x, bullets[j]->GetPosition().y);
							glVertex2f(asteroids[i]->GetPosition().x, asteroids[i]->GetPosition().y);
						}
					}
					glEnd();
				}

			}
		}

	}

}

//TODO:fix
void Game::CalculateFrameRate() {

	clock_t currentTicks, deltaTicks;
	clock_t fps = 0;

	while (true)// your main loop. could also be the idle() function in glut or whatever
	{
		currentTicks = clock();

		Render();

		deltaTicks = clock() - currentTicks; //the time, in ms, that took to render the scene

		if (deltaTicks > 0) {

			fps = CLOCKS_PER_SEC / deltaTicks;
		}
			
		std::cout << fps << std::endl;
	}
}

void Game::InputController() {

	if (inputManager.GetW()) {

		player->Impulse();
		player->SetIsThrusterOn(true);
	}
	else {

		player->SetIsThrusterOn(false);
	}

	if (inputManager.GetA()) {

		player->RotateLeft();
	}

	if (inputManager.GetD()) {

		player->RotateRight();
	}

	if (inputManager.GetR() && inputCounter == 0) {

		RemoveAsteroid();

		ResetInputCounter();
	}

	if (inputManager.GetT() && inputCounter == 0) {

		AddAsteroid();

		ResetInputCounter();
	}

	if (inputManager.GetG() && inputCounter == 0) {

		SwitchingDebuggerMode();

		ResetInputCounter();
	}

	if (inputManager.GetY()) {

		RespawnPlayer();
	}

	if (inputManager.GetSpace() && inputCounter == 0) {

		shootBullet();

		ResetInputCounter();
	}
}

InputManager Game::GetInputManager() {

	return inputManager;
}

void Game::ResetInputCounter() {

	inputCounter = 10;
}

