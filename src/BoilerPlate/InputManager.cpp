#include "InputManager.hpp"

InputManager::InputManager() {

	wKey = false;
	aKey = false;
	dKey = false;
	fKey = false;
	gKey = false;
	rKey = false;
	tKey = false;
	yKey = false;
	spaceKey = false;
}

//setters
void InputManager::SetW(bool wState) {

	wKey = wState;
}

void InputManager::SetA(bool aState) {

	aKey = aState;
}

void InputManager::SetD(bool dState) {

	dKey = dState;
}

void InputManager::SetF(bool fState) {

	fKey = fState;
}

void InputManager::SetG(bool gState) {

	gKey = gState;
}

void InputManager::SetR(bool rState) {

	rKey = rState;
}

void InputManager::SetT(bool tState) {

	tKey = tState;
}

void InputManager::SetY(bool yState) {

	yKey = yState;
}

void InputManager::SetSpace(bool spaceState) {

	spaceKey = spaceState;
}


//getters
bool InputManager::GetW() {

	return wKey;
}

bool InputManager::GetA() {

	return aKey;
}

bool InputManager::GetD() {

	return dKey;
}

bool InputManager::GetF() {

	return fKey;
}

bool InputManager::GetG() {

	return gKey;
}

bool InputManager::GetR() {

	return rKey;
}

bool InputManager::GetT() {

	return tKey;
}

bool InputManager::GetY() {

	return yKey;
}

bool InputManager::GetSpace() {

	return spaceKey;
}
