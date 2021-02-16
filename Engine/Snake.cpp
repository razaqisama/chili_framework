#include "Snake.h"
#include <assert.h>
Snake::Snake(const Location& loc)
{
	seg[0].initHead(loc);
}

void Snake::moveBy(const Location& deltaLoc)
{
	for (int i = nSegments - 1; i > 0; i--) 
	{
		seg[i].follow(seg[i - 1]);
	}
	seg[0].moveBy(deltaLoc);
}

void Snake::grow()
{
	if (nSegments < segmentMax) 
	{
		seg[nSegments].initBody();
		nSegments++;
	}
}

void Snake::draw(Board& brd) const
{
	for (int i = 0; i < nSegments; i++)
	{
		seg[i].draw(brd);
	}
}

void Snake::Segment::initHead(const Location& in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::initBody()
{
	c = Snake::bodyColor;
}

void Snake::Segment::follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::draw(Board& brd) const
{
	brd.drawCell(loc, c);
}

void Snake::Segment::moveBy(const Location& deltaLoc)
{
	assert(abs(deltaLoc.x) + abs(deltaLoc.y) == 1);

	loc.add(deltaLoc);
}
