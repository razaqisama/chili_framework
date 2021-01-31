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
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::drawPlayer()
{
	for (int i = playerX; i < playerX + playerWidth; i++) 
	{
		for (int j = playerY; j < playerY + playerHeight; j++) 
		{
			gfx.PutPixel(i, j, 25, 231, 114);
		}
	}
}

void Game::movePlayer()
{
	if ((playerX + playerVelocityX > 0) && ((playerX + playerWidth) + playerVelocityX < gfx.ScreenWidth))
	{
		playerX += playerVelocityX;
	}
	else {
		playerVelocityX = 0;
	}
	if ((playerY + playerVelocityY > 0) && ((playerY + playerHeight) + playerVelocityY < gfx.ScreenHeight))
	{
		playerY += playerVelocityY;
	}
	else {
		playerVelocityY = 0;
	}
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (playerVelocityY > playerMaxVelocity * -1)
		{
			playerVelocityY--;
		}
	}
	else if (playerVelocityY < 0)
	{
		playerVelocityY++;
	}


	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (playerVelocityY < playerMaxVelocity)
		{
			playerVelocityY++;
		}
	}
	else if (playerVelocityY > 0) {
		playerVelocityY--;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (playerVelocityX < playerMaxVelocity)
		{
			playerVelocityX++;
		}
	}
	else if (playerVelocityX > 0) {
		playerVelocityX--;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (playerVelocityX > playerMaxVelocity * -1)
		{
			playerVelocityX--;
		}
	}
	else if (playerVelocityX < 0) {
		playerVelocityX++;
	}

	movePlayer();
}

void Game::ComposeFrame()
{
	drawPlayer();
}
