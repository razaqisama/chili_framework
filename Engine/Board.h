#pragma once
#include "Location.h"
#include "Graphics.h"

class Board {
public:
	Board(Graphics& gfx);
	void drawCell( const Location& loc, Color c);
	int getWidth() const;
	int getHeight() const;

private:
	static constexpr int dimension = 20;
	static constexpr int width = 40;
	static constexpr int height = 30;

	Graphics& gfx;
};