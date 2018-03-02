#pragma once
#include <string>
#include <iostream>
#include "includeSDL.hpp"

class TextRender {

	TTF_Font *font;

public:
	TextRender(int gameScreenWidth, int gameScreenHeight);
	bool InitFont();
	unsigned int power_two_floor(unsigned int val);
	void RenderText(std::string message, SDL_Color color, float x, float y, int size);
	void RenderGameFont();
	//void RenderGameOverScreen();
	//void RenderScore();
};
