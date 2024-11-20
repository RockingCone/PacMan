#pragma once
#include "pacman.h"

Pacman::~Pacman(){};

void Pacman::Render(Color background, float scale, Camera2D camera)
{
    BeginMode2D(camera);
    Vector2 pos = GetPos();
    int xDir = GetDir().x;
    int yDir = GetDir().y;
    DrawCircleV(pos, size, color);
    if (frame > 5 * scale)
        frame = 0;
    switch(xDir)
    {
        case(1):
            DrawTriangle(pos, {pos.x + size, pos.y + frame}, {pos.x + size, pos.y - frame}, background);
            break;
        case(-1):
            DrawTriangle(pos, {pos.x - size, pos.y - frame}, {pos.x - size, pos.y + frame}, background);
            break;
        case(0):
            switch(yDir){
                case(1):
                    DrawTriangle(pos, {pos.x - frame, pos.y + size}, {pos.x + frame, pos.y + size}, background);
                    break;
                case(-1):
                    DrawTriangle(pos, {pos.x + frame, pos.y - size}, {pos.x - frame, pos.y - size}, background);
                    break;
            }
    }
    frame += scale;
    EndMode2D();
}