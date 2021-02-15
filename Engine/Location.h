#pragma once
struct Location
{
	void add(const Location& val)
	{
		x += val.x;
		y += val.y;
	}
	int x;
	int y;
};