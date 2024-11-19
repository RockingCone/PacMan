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
#include <string>

int main ()
{
	//// Main Variables
	// Window Variables
	float scale = 3;
	short unsigned int cellSize = 8 * scale;
	int screenW = 224 * scale;
	int screenH = 288 * scale;

	// Score Variables
	unsigned int score = 0;
	unsigned int highScore = 0;
	int clearedDots = 0;
	std::string scoreStr = "0";
	std::string highScoreStr = "0";
	bool spawn1 = 0;
	bool spawn2 = 0;

	bool active = 1;
	short unsigned int level = 0;
	Vector2 input = {0,0};
	Pacman player({14.0f * cellSize, (float)int(23.5f * cellSize)}, {1,0});
	Vector2 playerPos = {14 * scale, 13 * scale};
	player.SetSize(cellSize / 2);
	short unsigned int lvl0[31][28] = 
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
	short unsigned int lvl[31][28] = {0};
	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			lvl[i][j] = lvl0[i][j];
		}
	}

	// Window Initialization
	InitWindow(screenW, screenH, "Pac-Man");
	SetTargetFPS(60);

	// Camera Initialization
	Camera2D camera = {0};
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;
	camera.offset = {0, cellSize * 2.0f};
	camera.target = {0, 0};

	while (active)
	{
		if (IsKeyPressed(KEY_ESCAPE) || IsKeyDown(KEY_ESCAPE))
		{
			active = 0;
			break;
		}

		#pragma region Input_Management
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
		#pragma endregion Input_Management

		#pragma region Rendering
		BeginDrawing();
			ClearBackground(BLACK);

			// Render Score
			DrawText("HIGH", 10 * cellSize, 0, cellSize, WHITE);
			DrawText("SCORE", 15 * cellSize, 0, cellSize, WHITE);
			DrawText(scoreStr.c_str(), 5 * cellSize, cellSize, cellSize, WHITE);
			DrawText(highScoreStr.c_str(), 14 * cellSize, cellSize, cellSize, WHITE);
			
			BeginMode2D(camera);
			for (int i = 0; i < 28; i++)
			{
				for (int j = 0; j < 31; j++)
				{
					switch(lvl[j][i])
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
						case(4):
							DrawCircle(i * cellSize + (cellSize / 3), j * cellSize + (cellSize * (2/3)), cellSize / 3, RED);
							DrawCircle(i * cellSize + (cellSize * (2/3)), j * cellSize + (cellSize * (2/3)), cellSize / 3, RED);
							DrawLine(i * cellSize + (cellSize * (2/3)), j * cellSize + (cellSize / 3), i * cellSize + (cellSize * (2/3)), j * cellSize, GREEN);
							DrawLine(i * cellSize + (cellSize / 3), j * cellSize + (cellSize / 3), i * cellSize + (cellSize * (2/3)), j * cellSize, GREEN);
							break;
						default:
							std::cout << "Err : Invalid Map Symbol";
					}
				}
			}
			EndMode2D();

			// Render Entities
			player.Render(BLACK, scale, camera);

		EndDrawing();
		#pragma endregion Rendering

		// Player Position
		playerPos = {player.GetPos().x, player.GetPos().y};
		int playerX = playerPos.x / cellSize;
		int playerY = playerPos.y / cellSize;

		#pragma region Scoring
		switch(lvl[playerY][playerX])
		{
			case(2):
				score += 10;
				clearedDots++;
				break;
			case(3):
				score += 40;
				clearedDots++;
				break;
			case(4):
				score += 100;
				break;
			case(5):
				score += 300;
				break;
			case(6):
				score += 500;
				break;
			case(7):
				score += 700;
				break;
			case(8):
				score += 1000;
				break;
			case(9):
				score += 2000;
				break;
			case(10):
				score += 3000;
				break;
			case(11):
				score += 5000;
				break;
		}
		if (lvl[playerY][playerX] != 1)
			lvl[playerY][playerX] = 0;
		scoreStr = std::to_string(score);

		// Spawn Fruits When Needed
		if (clearedDots == 70 && spawn1 == 0 && level == 0)
		{
			switch(level)
			{
				case(0):
					// Cherry
					lvl[17][14] = 4;
					break;
				case(1):
					// Strawberry
					lvl[17][14] = 5;
					break;
				case 2 ... 3:
					// Orange
					lvl[17][14] = 6;
					break;
				case 4 ... 5:
					// Apple
					lvl[17][14] = 7;
					break;
				case 6 ... 7:
					// Pineapple
					lvl[17][14] = 8;
					break;
				case 8 ... 9:
					// Spaceship
					lvl[17][14] = 9;
					break;
				case 10 ... 11:
					// Bell
					lvl[17][14] = 10;
					break;
				default:
					lvl[17][14] = 11;
					break;
			}
			spawn1 = 1;
		}
		else if (clearedDots == 170 && spawn2 == 0 && level == 0)
		{
			switch(level)
			{
				case(0):
					// Cherry
					lvl[17][14] = 4;
					break;
				case(1):
					// Strawberry
					lvl[17][14] = 5;
					break;
				case 2 ... 3:
					// Orange
					lvl[17][14] = 6;
					break;
				case 4 ... 5:
					// Apple
					lvl[17][14] = 7;
					break;
				case 6 ... 7:
					// Pineapple
					lvl[17][14] = 8;
					break;
				case 8 ... 9:
					// Spaceship
					lvl[17][14] = 9;
					break;
				case 10 ... 11:
					// Bell
					lvl[17][14] = 10;
					break;
				default:
					lvl[17][14] = 11;
					break;
			}
			spawn2 = 1;
		}

		// Next Level Condition
		if (clearedDots == 244)
		{
			// Reset Variables
			level++;
			clearedDots = 0;
			spawn1 = 0;
			spawn2 = 0;
			for (int i = 0; i < 31; i++)
			{
				for (int j = 0; j < 28; j++)
				{
					lvl[i][j] = lvl0[i][j];
				}
			}

			// Reset Player
			player.SetPos({14.0f * cellSize, (float)int(23.5f * cellSize)});
			player.SetDir({1,0});

			// Reset Ghosts
		}
		#pragma endregion Scoring

		#pragma region Player_Movement
		int nextX = playerX + player.GetDir().x;
		int nextY = playerY + player.GetDir().y;
		int inpX = playerX + input.x;
		int inpY = playerY + input.y;
		if (nextX < 0 || nextX > 28 || nextY < 0 || nextY > 31 || lvl[nextY][nextX] == 1)
		{
			if (playerY == 14)
			{
				if (nextX <= -1)
					player.SetPos({28.5f * cellSize, 14.5f * cellSize});
				else if (nextX >= 28)
					player.SetPos({0.5f * cellSize, 14.5f * cellSize});
				else
				{
					player.SetDir({0,0});
					player.SetPos({float(playerX + 0.5f) * cellSize, float(playerY + 0.5f) * cellSize});
				}
			}
			else 
			{
				player.SetDir({0,0});
				player.SetPos({float(playerX + 0.5f) * cellSize, float(playerY + 0.5f) * cellSize});
			}
		}
		else if (lvl[inpY][inpX] != 1 && !(player.GetDir().x == input.x && player.GetDir().y == input.y))
		{
			player.SetPos({float(playerX + 0.5f) * cellSize, float(playerY + 0.5f) * cellSize});
			player.SetDir(input);
		}
		player.Move(scale);
		#pragma endregion Player_Movement
	}
}