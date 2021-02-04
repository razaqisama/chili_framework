#pragma once
#include "Player.h"
#include "Graphics.h"

class Enemy
{
public:
	Enemy(int in_x, int in_y);
	void follow(Player& player);
	void draw(Graphics& gfx) const;
	void move(Graphics& gfx);

public: 
	static constexpr int width = 25;
	static constexpr int height = 25;

private:
	int x;
	int y;
	int vx = 0;
	int vy = 0;
};