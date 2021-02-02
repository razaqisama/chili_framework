#pragma once
#include "Graphics.h"
#include "MainWindow.h"
class Player
{
public: 
	Player(int in_x, int in_y);
	void move(Graphics& gfx);
	void moveControl(MainWindow& wnd);

	void draw(Graphics& gfx) const;
	int getX();
	int getY();
	bool isCaptured();
	void setCaptured(bool capture);
public :
	static constexpr int width = 25;
	static constexpr int height = 25;
	static constexpr int maxV = 7;

private:
	int x;
	int y;
	int vx = 0;
	int vy = 0;
	bool captured = false;
};