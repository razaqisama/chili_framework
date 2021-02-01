#pragma once
#include "Graphics.h"
#include "Colors.h"
class Player
{
public: 
	Player(int in_x, int in_y);
	void move(Graphics& gfx);
	void draw(Graphics& gfx) const;

	int x;
	int y;
	int vx = 0;
	int vy = 0;
	static constexpr int width = 25;
	static constexpr int height = 25;
	static constexpr int maxV = 7;


private:
};