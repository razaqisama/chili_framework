/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd( gfx ),
	rng(std::random_device()()),
	snek({2,2})
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if ( wnd.kbd.KeyIsPressed(VK_UP) && (deltaLoc.y != 1) )
	{
		deltaLoc = { 0,-1 };
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN) && (deltaLoc.y != -1) )
	{
		deltaLoc = { 0, 1 };
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT) && (deltaLoc.x != 1) )
	{
		deltaLoc = { -1,0 };
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT) && (deltaLoc.x != -1))
	{
		deltaLoc = { 1,0 };
	}



	counterFrame++;

	if (counterFrame > maxFPS) {
		counterFrame = 0;
		if (wnd.kbd.KeyIsPressed(VK_SHIFT))
		{
			snek.grow();
		}
		snek.moveBy(deltaLoc);
	}
}

void Game::ComposeFrame()
{
	snek.draw(brd);

}
