#pragma once

class InputManager {

private:
	bool wKey;
	bool aKey;
	bool dKey;
	bool sKey;
	bool fKey;
	bool gKey;
	bool rKey;
	bool tKey;
	bool yKey;
	bool spaceKey;

public:
	//costructor
	InputManager();

	//getters and setters
	void SetW(bool wState);
	void SetA(bool sSatet);
	void SetD(bool dState);
	void SetF(bool fState);
	void SetG(bool gState);
	void SetR(bool rState);
	void SetT(bool tState);
	void SetY(bool yState);
	void SetSpace(bool spaceState);

	bool GetW();
	bool GetA();
	bool GetD();
	bool GetF();
	bool GetG();
	bool GetR();
	bool GetT();
	bool GetY();
	bool GetSpace();
};
