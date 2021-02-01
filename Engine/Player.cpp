#include "Player.h"

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

void Player::moveControl(MainWindow& wnd)
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (vy > maxV * -1)
		{
			vy--;
		}
	}
	else if (vy < 0)
	{
		vy++;
	}


	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (vy < maxV)
		{
			vy++;
		}
	}
	else if (vy > 0) {
		vy--;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (vx < maxV)
		{
			vx++;
		}
	}
	else if (vx > 0) {
		vx--;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (vx > maxV * -1)
		{
			vx--;
		}
	}
	else if (vx < 0) {
		vx++;
	}
}

void Player::draw(Graphics& gfx) const
{
	gfx.drawRect(x, y, width, height, Colors::MakeRGB(255,233,213));
}

int Player::getX()
{
	return x;
}

int Player::getY()
{
	return y;
}
