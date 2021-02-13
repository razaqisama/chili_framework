#include "Board.h"
#include <assert.h>
Board::Board(Graphics& gfx)
	:
	gfx( gfx )
{

}

void Board::drawCell(Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension , c);
}

int Board::getWidth()
{
	return width;
}

int Board::getHeight()
{
	return height;
}
