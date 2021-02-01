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
	rng( rd()),
	xDist(50, 770),
	yDist(50, 570),
	vDist(-3, 3),
	player( 25, 25),
	enemy(700 , 500)
{
	for (int i = 0; i < allPoos; i++)
	{
		poos[i].init(xDist(rng), yDist(rng), vDist(rng), vDist(rng));
	}
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
	enemy.follow(player);
	enemy.move(gfx);

	player.moveControl(wnd);
	player.move(gfx);

	for (int i = 0; i < allPoos; i++)
	{
		poos[i].updatePosition();
		poos[i].processConsumption(player);
	}

}

void Game::ComposeFrame()
{
	for (int i = 0; i < allPoos; i++)
	{
		if (!poos[i].IsEaten())
		{
			poos[i].draw(gfx);
		}
	}
	player.draw(gfx);
	enemy.draw(gfx);
}
