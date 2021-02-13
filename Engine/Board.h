#pragma once
#include "Location.h"
#include "Graphics.h"

class Board {
public:
	Board(Graphics& gfx);
	void drawCell(Location& loc, Color c);
	int getWidth();
	int getHeight();

private:
	static constexpr int dimension = 20;
	static constexpr int width = 40;
	static constexpr int height = 30;

	Graphics& gfx;
};