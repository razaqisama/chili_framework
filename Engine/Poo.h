#pragma once
#include "Graphics.h"
#include "Player.h"
class Poo
{
public: 
	void init(int in_x, int in_y, int in_vx, int in_vy);
	void draw(Graphics& gfx) const;
	void updatePosition();
	void processConsumption(Player& player);
	bool IsEaten();
	
public:
	static constexpr int width = 25;
	static constexpr int height = 25;

private:
	int x;
	int y;
	int vx;
	int vy;

	bool isEaten = false;
	bool initialized = false;
};