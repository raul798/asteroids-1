#include "Game.hpp"

Game::Game() {

	player = new Player();
	numberOfAsteroids = initialNumberOfAsteroids;
	stageCounter = 0;
	asteroids = std::vector<Asteroid*>(numberOfAsteroids);
	SpawnAsteroids();
	ResetInputCounter();
	storageDeltaTime = std::vector<Vector2>(20);
	FillStorageDeltaTime();
	isFrameRateOn = false;
	playerRemainingLives = 3;
	invulnerabilityTimeCounter = 0.0f;
	playerScore = 0;
	livesPerScoreCounter = 1;
	textManager->InitFont();
	textManager = new TextManager(gameScreenWidth, gameScreenHeight, fontSize);
	SetFontColor(255, 255, 255, 255);
	soundManager = irrklang::createIrrKlangDevice();
	soundManager->setSoundVolume(1.0f);
}

Game::~Game(){

	RemoveFromMemory();
}

void Game::Update(int screenWidth, int screenHeight, float deltaTime) {

	UpdateScreenDimensions(screenWidth, screenHeight);
	UpdateInputController();
	CheckPlayerInvulnerability();
	player->Update(screenWidth, screenHeight, deltaTime);
	UpdateAllAsteroids(screenWidth, screenHeight, deltaTime);
	UpdateAllBullets(screenWidth, screenHeight, deltaTime);
}

void Game::Render() {

	DrawPlayerRemainingLives();
	player->Render();
	RenderAsteroids();
	RenderBullets();
	GraphFrameRate();
	RenderScore();
	RenderGameOverScreen();
}

void Game::SetFontColor(int r, int g, int b, int a) {

	fontColor.r = r;
	fontColor.g = g;
	fontColor.b = b;
	fontColor.a = a;
}

void Game::RenderGameOverScreen() {


	if (playerRemainingLives <= 0) {

		//Score Position
		float xAxisGameOverText = -60.0f;
		float yAxisGameOverText = (gameScreenHeight / 2) - 30.0f;

		textManager->RenderText("Game Over", fontColor, xAxisGameOverText, xAxisGameOverText, fontSize);
		textManager->RenderText("Press Y to Restart", fontColor, xAxisGameOverText - 150.0f, xAxisGameOverText - 100.0f, fontSize);
	}
}

void Game::RenderScore() {

	//Score Position
	float xAxisScore = 0.0f;
	float yAxisScore = (gameScreenHeight / 2) - 70.0f;

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	textManager->RenderText(std::to_string(playerScore), fontColor, xAxisScore, yAxisScore, fontSize);
}

void Game::UpdateAllAsteroids(int screenWidth, int screenHeight, float deltaTime) {

	DetermineDebuggerState();
	CollisionOfTheShip();
	SpawnAsteroidsPerStage();
	
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
		numberOfAsteroids = static_cast<int>(asteroids.size());
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
			numberOfAsteroids = static_cast<int>(asteroids.size());
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

	if (player->GetDebuggerState() == false && player->GetIsInvulnerabilityOn() == false) {

		for (int i = 0; i < asteroids.size(); i++) {

			distanceBetweenEntities = CalculateDistanceBetweenEntities(player->GetPosition(), asteroids[i]->GetPosition());

			if (IsInCollisionRange(distanceBetweenEntities, player->GetEntityRadius() + asteroids[i]->GetEntityRadius())) {

				player->SetIsRendering(false);
				player->SetIsInvulnerabilityOn(true);
				playerRemainingLives--;
				RespawnPlayer();

				if (asteroids[i]->GetAsteroidSize() == 3) {

					soundManager->play2D("sound/bangLarge.wav");
				}
				if (asteroids[i]->GetAsteroidSize() == 2) {

					soundManager->play2D("sound/bangMedium.wav");
				}
				if (asteroids[i]->GetAsteroidSize() == 1) {

					soundManager->play2D("sound/bangSmall.wav");
				}


			}
		}
	}
}

void Game::RespawnPlayer() {

	if (playerRemainingLives > 0) {

		player->RespawnShip();

		soundManager->play2D("sound/beat1.wav");
	}
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
			soundManager->play2D("sound/Fire.wav");
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

					//divide asteroids depending on size and adding to the player score
					if(asteroids[j]->GetAsteroidSize() == 3) {

						asteroids.push_back(new Asteroid(2, asteroids[j]->GetPosition()));
						asteroids.push_back(new Asteroid(2, asteroids[j]->GetPosition()));

						playerScore += 20;

						soundManager->play2D("sound/bangLarge.wav");
					}
					if(asteroids[j]->GetAsteroidSize() == 2) {

						asteroids.push_back(new Asteroid(1, asteroids[j]->GetPosition()));
						asteroids.push_back(new Asteroid(1, asteroids[j]->GetPosition()));

						playerScore += 50;

						soundManager->play2D("sound/bangMedium.wav");
					}
					if (asteroids[j]->GetAsteroidSize() == 1) {

						playerScore += 100;

						soundManager->play2D("sound/bangSmall.wav");
					}
					
					//remove the asteroid and the bullet on impact
					asteroids.erase(asteroids.begin() + j);
					bullets.erase(bullets.begin() + i);
					numberOfAsteroids = static_cast<int>(asteroids.size());

					//add lives depending on score
					AdditionalLivesPerScore();
					std::cout << playerScore << std::endl;
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

void Game::InputController() {

	if (inputManager.GetW()) {

		player->Impulse();
		player->SetIsThrusterOn(true);
		soundManager->play2D("sound/thrust.wav");
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

	if (inputManager.GetF() && inputCounter == 0) {

		ToggleFramerate();

		ResetInputCounter();
	}

	if (inputManager.GetY()) {

		if (playerRemainingLives == 0) {

			ResetGame();
		}
	}

	if (inputManager.GetSpace() && inputCounter == 0) {

		if (player->GetCanPlayerShoot() == true) {

			shootBullet();

			ResetInputCounter();
		}
	}
}

InputManager Game::GetInputManager() {

	return inputManager;
}

void Game::ResetInputCounter() {

	inputCounter = 10;
}

void Game::FillStorageDeltaTime(){
	
	storageDeltaTimeCounter = 0;

	for (int i = 0; i < storageDeltaTime.size(); i++) {

		storageDeltaTime[i].x = static_cast<float>(i);
		storageDeltaTime[i].y = DESIRED_FRAME_TIME;
	}
}

float Game::CalculateFrameRate(double endTime, double startTime) {

	float deltaTime = DESIRED_FRAME_TIME - (static_cast<float>(endTime) - static_cast<float>(startTime));

	return deltaTime;
}

void Game::UpdateFrameRate(double endTime, double startTime) {

	float deltaTime = CalculateFrameRate(endTime, startTime);

	storageDeltaTime[storageDeltaTimeCounter] = Vector2(static_cast<float>(storageDeltaTimeCounter), deltaTime);

	storageDeltaTimeCounter++;

	if (storageDeltaTimeCounter >= FRAME_STORAGE_LIMIT) {

		storageDeltaTimeCounter = 0;
	}
}

void Game::GraphFrameRate() {

	if (isFrameRateOn == true) {

		DrawGraphAxes();

		DrawFrameRateGraph();
	}
}

void Game::DrawGraphAxes() {

	//Graph position
	float xAxisGraphPosition = (gameScreenWidth / 2) - 250.0f;
	float yAxisGraphPosition = 20.0f - (gameScreenHeight / 2);

	//green color for the graph
	glColor3f(0.0f, 1.0f, 0.0f);
	glLoadIdentity();
	glTranslatef(xAxisGraphPosition, yAxisGraphPosition, 0.0f);

	//graphic axes
	glBegin(GL_LINE_STRIP);
	glVertex2f(0.0f, 100.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(200.0f, 0.0f);
	glEnd();
}

void Game::DrawFrameRateGraph() {

	//graph frame rate
	glBegin(GL_LINE_STRIP);

	//green color for the graph
	glColor3f(1.0f, 1.0f, 0.0f);

	for (int i = 0; i < FRAME_STORAGE_LIMIT; i++) {

		glVertex2f(FRAME_RATE_SCALE_X * storageDeltaTime[i].x, FRAME_RATE_SCALE_Y * (DESIRED_FRAME_TIME - storageDeltaTime[i].y));
	}
	glEnd();
}

void Game::ToggleFramerate() {

	if (isFrameRateOn == false) {

		isFrameRateOn = true;
	}
	else {

		isFrameRateOn = false;
	}
}

void Game::DrawPlayerRemainingLives() {

	for (int i = 1; i <= playerRemainingLives; i++) {

		//Player Lives Position
		float xAxisLivesPosition = (gameScreenWidth / 2) + 10.0f + i * distanceBetweenLives;
		float yAxisLivesPosition = (gameScreenHeight / 2) - 30.0f;

		//render player lives
		glLoadIdentity();

		//It translate according to the screenWidth and Height
		glTranslatef(xAxisLivesPosition, yAxisLivesPosition, 0.0f);
		player->DrawPlayerLives();
	}
}

void Game::CheckPlayerInvulnerability() {

	if (player->GetIsInvulnerabilityOn() == true) {

		player->SetCanPlayerShoot(false);
		invulnerabilityTimeCounter++;

		if (invulnerabilityTimeCounter >= 200.0f) {

			player->SetCanPlayerShoot(true);
			player->SetIsInvulnerabilityOn(false);
			invulnerabilityTimeCounter = 0.0f;

			soundManager->play2D("sound/beat2.wav");
		}
	}
}

void Game::UpdateInputController() {

	InputController();

	if (inputCounter > 0) {

		inputCounter--;
	}
}

void Game::UpdateScreenDimensions(int screenWidth, int screenHeight) {

	gameScreenWidth = screenWidth;
	gameScreenHeight = screenHeight;
}

void Game::SpawnAsteroidsPerStage() {

	if (asteroids.size() == 0) {

		//keep track of the number of asteroids
		stageCounter++;
		numberOfAsteroids = initialNumberOfAsteroids + stageCounter;

		for (int i = 0; i < numberOfAsteroids; i++) {

			asteroids.push_back(new Asteroid());
		}
	}
}

void Game::ResetGame() {

	player->SetDebuggerState(false);
	asteroids.clear();
	stageCounter = 0;
	numberOfAsteroids = initialNumberOfAsteroids;
	playerRemainingLives = 3;
	player->RespawnShip();
	playerScore = 0;
	livesPerScoreCounter = 1;
	player->SetIsInvulnerabilityOn(true);
	player->SetCanPlayerShoot(true);

	for (int i = 0; i < numberOfAsteroids; i++) {

		asteroids.push_back(new Asteroid());
	}
}

void Game::AdditionalLivesPerScore(){

	if (playerScore / livesPerScoreCounter >= scoreToGetLife) {
		
		livesPerScoreCounter++;
		playerRemainingLives++;
		soundManager->play2D("sound/extraShip.wav");
	}
	
}