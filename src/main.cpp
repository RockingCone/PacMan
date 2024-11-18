/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

For a C++ project simply rename the file to .cpp and re-run the build script 

-- Copyright (c) 2020-2024 Jeffery Myers
--
--This software is provided "as-is", without any express or implied warranty. In no event 
--will the authors be held liable for any damages arising from the use of this software.

--Permission is granted to anyone to use this software for any purpose, including commercial 
--applications, and to alter it and redistribute it freely, subject to the following restrictions:

--  1. The origin of this software must not be misrepresented; you must not claim that you 
--  wrote the original software. If you use this software in a product, an acknowledgment 
--  in the product documentation would be appreciated but is not required.
--
--  2. Altered source versions must be plainly marked as such, and must not be misrepresented
--  as being the original software.
--
--  3. This notice may not be removed or altered from any source distribution.

*/

#include "raylib.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "pacman.cpp"

int main ()
{
	// Main Variables
	int screenW = 224;
	int screenH = 288;
	bool active = 1;
	unsigned int score = 0;
	short unsigned int level = 0;
	short unsigned int cellSize = 8;
	Vector2 input = {0,0};
	Pacman player({14 * cellSize, int(23.5 * cellSize)}, {-1,0});
	Vector2 playerPos = {14, 13};
	player.SetSize(cellSize / 2);
	#pragma region Level_One
	short unsigned int lvl1[31][28] = 
	{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1},
	{1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,2,1},
	{1,3,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,3,1},
	{1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,2,1},
	{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
	{1,2,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,2,1},
	{1,2,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,2,1},
	{1,2,2,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,2,2,1},
	{1,1,1,1,1,1,2,1,1,1,1,1,0,1,1,0,1,1,1,1,1,2,1,1,1,1,1,1},
	{0,0,0,0,0,1,2,1,1,1,1,1,0,1,1,0,1,1,1,1,1,2,1,0,0,0,0,0},
	{0,0,0,0,0,1,2,1,1,0,0,0,0,0,0,0,0,0,0,1,1,2,1,0,0,0,0,0},
	{0,0,0,0,0,1,2,1,1,0,1,1,1,1,1,1,1,1,0,1,1,2,1,0,0,0,0,0},
	{1,1,1,1,1,1,2,1,1,0,1,0,0,0,0,0,0,1,0,1,1,2,1,1,1,1,1,1},
	{0,0,0,0,0,0,2,0,0,0,1,0,0,0,0,0,0,1,0,0,0,2,0,0,0,0,0,0},
	{1,1,1,1,1,1,2,1,1,0,1,0,0,0,0,0,0,1,0,1,1,2,1,1,1,1,1,1},
	{0,0,0,0,0,1,2,1,1,0,1,1,1,1,1,1,1,1,0,1,1,2,1,0,0,0,0,0},
	{0,0,0,0,0,1,2,1,1,0,0,0,0,0,0,0,0,0,0,1,1,2,1,0,0,0,0,0},
	{0,0,0,0,0,1,2,1,1,0,1,1,1,1,1,1,1,1,0,1,1,2,1,0,0,0,0,0},
	{1,1,1,1,1,1,2,1,1,0,1,1,1,1,1,1,1,1,0,1,1,2,1,1,1,1,1,1},
	{1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1},
	{1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,2,1},
	{1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,2,1},
	{1,3,2,2,1,1,2,2,2,2,2,2,2,0,0,2,2,2,2,2,2,2,1,1,2,2,3,1},
	{1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1},
	{1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1},
	{1,2,2,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,1,1,2,2,2,2,2,2,1},
	{1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1},
	{1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1},
	{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	#pragma endregion Level_One

	// Window Initialization
	InitWindow(screenW, screenH, "Pac-Man");
	SetTargetFPS(60);

	while (active)
	{
		if (WindowShouldClose())
		{
			active = false;
			break;
		}


		// Input Management
		if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_RIGHT)) && (IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN))){
			input = {0,0};
		}
		else if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_RIGHT))
			input = {0,0};
		else if (IsKeyDown(KEY_LEFT))
			input = {-1,0};
		else if (IsKeyDown(KEY_RIGHT))
			input = {1,0};
		else if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_DOWN))
			input = {0,0};
		else if (IsKeyDown(KEY_UP))
			input = {0,-1};
		else if (IsKeyDown(KEY_DOWN))
			input = {0,1};

		// Rendering
		BeginDrawing();
		ClearBackground(BLACK);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 0; j < 31; j++)
			{
				switch(lvl1[j][i])
				{
					case(0):
						break;
					case(1):
						DrawRectangle(i * cellSize, j * cellSize, cellSize, cellSize, BLUE);
						break;
					case(2):
						DrawCircle(i * cellSize + (cellSize / 2), j * cellSize + (cellSize / 2), cellSize / 5, YELLOW);
						break;
					case(3):
						DrawCircle(i * cellSize + (cellSize / 2), j * cellSize + (cellSize / 2), cellSize / 2, YELLOW);
						break;
					default:
						std::cout << "Err : Invalid Map Symbol";
				}
			}
		}
		player.Render(BLACK);
		EndDrawing();

		// Player Movement
		playerPos = {player.GetPos().x / cellSize, player.GetPos().y / cellSize};
		int nextX = playerPos.x + player.GetDir().x * 0.5f;
		int nextY = playerPos.y + player.GetDir().y * 0.5f;
		if (nextX < 0 || nextX > 28 || nextY < 0 || nextY > 31)
			player.SetDir({0,0});
		else if (lvl1[nextY][nextX] == 1)
			player.SetDir({0,0});
		else if (lvl1[int(playerPos.y + input.y * 0.5f)][int(playerPos.x + input.x * 0.5f)] != 1)
			player.SetDir(input);
		player.Move();
	}
}