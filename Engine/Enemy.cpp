#include "Enemy.h"

Enemy::Enemy(int in_x, int in_y)
{
	x = in_x;
	y = in_y;
}

void Enemy::follow(Player& player)
{
	int dx = x - player.getX();
	int dy = y - player.getY();

	if (dx < 0)
	{
		vx = 4;
	}
	else 
	{
		vx = -4;
	}

	if (dy < 0)
	{
		vy = 4;
	}
	else 
	{
		vy = -4;
	}
}

void Enemy::draw(Graphics& gfx) const
{
	gfx.drawRect(x, y, width, height, Colors::MakeRGB(255, 20, 20));
}

void Enemy::move(Graphics& gfx)
{
	if ((x + vx > 0) && ((x + width) + vx < gfx.ScreenWidth))
	{
		x += vx;
	}
	else {
		vx = 0;
	}
	if ((y + vy > 0) && ((y + height) + vy < gfx.ScreenHeight))
	{
		y += vy;
	}
	else {
		vy = 0;
	}
}
