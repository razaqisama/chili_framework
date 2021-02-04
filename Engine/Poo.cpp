#include "Poo.h"

Poo::Poo(int in_x, int in_y, int in_vx, int in_vy)
{
	x = in_x;
	y = in_y;
	vx = in_vx;
	vy = in_vy;
}

void Poo::draw(Graphics& gfx)
{
	gfx.drawRect(x, y, width, height, Colors::MakeRGB(11, 191, 205));
}

void Poo::update()
{
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
