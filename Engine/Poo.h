#pragma once
#include "Graphics.h"
#include "Player.h"
class Poo
{
public: 
	void init(int in_x, int in_y, int in_vx, int in_vy);
	void draw(Graphics& gfx);
	void updatePosition();
	void processConsumption(Player& player);
	bool IsEaten();
	

private:
	int x;
	int y;
	int vx;
	int vy;

	static constexpr int width = 25;
	static constexpr int height = 25;
	static constexpr int maxV = 5;
	bool isEaten = false;
	bool initialized = false;
};