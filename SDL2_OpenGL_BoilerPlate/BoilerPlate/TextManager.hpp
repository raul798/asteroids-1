#pragma once
#include <string>
#include <iostream>
#include "includeSDL.hpp"

class TextManager {

private:
	TTF_Font *font;

public:
	TextManager(int gameScreenWidth, int gameScreenHeight);
	bool InitFont();
	unsigned int power_two_floor(unsigned int val);
	void RenderText(std::string message, SDL_Color color, float x, float y, int size);
};
