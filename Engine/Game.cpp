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
#include "Source/ParticleSystemData.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
	ParticleSystemData psData;
	psData.birthColor = Colors::Red;
	psData.deathColor = Colors::Yellow;
	psData.gravity = Vec2D(0.0f, 2.0f);
	psData.lifeTime = 4.0f;
	psData.maxVel = Vec2D(70.0f, 100.0f);
	psData.minVel = Vec2D(-70.0f, -100.0f);
	psData.position = Vec2D(400.0f, 100.0f);
	psData.shape = Shapes::SHAPE_CIRCLE;
	psData.minSize = 5.0f;
	psData.maxSize = 10.0f;
	psData.spawnRate = 5;
	ps = ParticleSystem2D(psData);
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
	const float dt = ft.Mark();
	ps.Advance(dt);
}

void Game::ComposeFrame()
{
	ps.Render(gfx);
}
