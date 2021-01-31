#pragma once
#include "Graphics.h"
#include "Colors.h"
class Player
{
public: 
	int x;
	int y;
	int vx;
	int vy;
	static constexpr int width = 25;
	static constexpr int height = 25;
	static constexpr int maxV = 10;

	void move(Graphics& gfx);
	void draw(Graphics& gfx) const;
private:
};