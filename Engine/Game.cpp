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
	gfx( wnd )
{
	player.x = 25;
	player.y = 25;
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::movePlayer()
{
	if ((player.x + player.vx > 0) && ((player.x + Player::width) + player.vx < gfx.ScreenWidth))
	{
		player.x += player.vx;
	}
	else {
		player.vx = 0;
	}
	if ((player.y + player.vy > 0) && ((player.y + Player::height) + player.vy < gfx.ScreenHeight))
	{
		player.y += player.vy;
	}
	else {
		player.vy = 0;
	}
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (player.vy > Player::maxV * -1)
		{
			player.vy--;
		}
	}
	else if (player.vy < 0)
	{
		player.vy++;
	}


	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (player.vy < Player::maxV)
		{
			player.vy++;
		}
	}
	else if (player.vy > 0) {
		player.vy--;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (player.vx < Player::maxV)
		{
			player.vx++;
		}
	}
	else if (player.vx > 0) {
		player.vx--;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (player.vx > Player::maxV * -1)
		{
			player.vx--;
		}
	}
	else if (player.vx < 0) {
		player.vx++;
	}

	player.move(gfx);
}

void Game::ComposeFrame()
{
	player.draw(gfx);
}
