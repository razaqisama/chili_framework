#include "player.h"

Player::Player(int in_x, int in_y)
{
	x = in_x;
	y = in_y;
}

void Player::move(Graphics& gfx)
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

void Player::draw(Graphics& gfx) const
{
	gfx.drawRect(x, y, width, height, Colors::MakeRGB(255,233,213));
}
