#pragma once
#include "pacman.h"

Pacman::~Pacman(){};

Pacman::Pacman(){};

void Pacman::Render(Color background){
    BeginDrawing();
    Vector2 pos = GetPos();
    int xDir = GetDir().x;
    int yDir = GetDir().y;
    DrawCircleV(pos, size, color);
    switch(xDir){
        case(1):
            DrawTriangle(pos, {pos.x + size, pos.y + frame}, {pos.x + size, pos.y - frame}, background);
            break;
        case(-1):
            DrawTriangle(pos, {pos.x - size, pos.y + frame}, {pos.x - size, pos.y - frame}, background);
            break;
        case(0):
            switch(yDir){
                case(1):
                    DrawTriangle(pos, {pos.x + frame, pos.y - size}, {pos.x - frame, pos.y - size}, background);
                    break;
                case(-1):
                    DrawTriangle(pos, {pos.x + frame, pos.y + size}, {pos.x - frame, pos.y - size}, background);
                    break;
            }
    }
}