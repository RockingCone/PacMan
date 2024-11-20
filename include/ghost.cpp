#pragma once
#include "ghost.h"

Ghost::~Ghost()
{

}

void Ghost::Render(float scale, Camera2D camera)
{
    BeginMode2D(camera);

    Vector2 pos = GetPos();
    DrawCircleV(pos, (size / 2), color);
    DrawRectangle(pos.x - (0.5 * size), pos.y, size, size * 0.5, color);

    EndMode2D();
}