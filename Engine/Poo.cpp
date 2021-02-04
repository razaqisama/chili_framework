#include "Poo.h"
#include <assert.h>

void Poo::init(int in_x, int in_y, int in_vx, int in_vy)
{
	assert(initialized == false);
	x = in_x;
	y = in_y;
	vx = in_vx;
	vy = in_vy;
	initialized = true;
}

void Poo::draw(Graphics& gfx) const
{
	assert(initialized == true);
	gfx.drawRect(x, y, width, height, Colors::MakeRGB(11, 191, 205));
}

void Poo::updatePosition()
{
	assert(initialized == true);
	if ( (x + vx > 0) && ( (x + width) + vx < Graphics::ScreenWidth) )
	{
		x += vx;
	}
	else {
		vx = vx * -1;
	}

	if ((y + vy > 0) && ((y + height) + vy < Graphics::ScreenHeight))
	{
		y += vy;
	}
	else
	{
		vy = vy * -1;
	}
}

void Poo::processConsumption(Player& player)
{
	assert(initialized == true);
	if ( (player.getX() < (x + width) ) && (player.getX() + Player::width > x) &&
		(player.getY() < y + height) && (player.getY() + Player::height > y) )
	{
		isEaten = true;
	}
}

bool Poo::IsEaten()
{
	assert(initialized == true);
	return isEaten;
}
