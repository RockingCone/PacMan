#pragma once
#include "entity.h"
#include <iostream>

Entity::~Entity(){}

Entity::Entity(){
    position = {0,0};
    direction = {0,0};
}

Entity::Entity(Vector2 pos, Vector2 dir){
    position = pos;
    direction = dir;
}

void Entity::SetDir(Vector2 dir){
    direction = dir;
}

Vector2 Entity::GetPos(){
    return position;
}

Vector2 Entity::GetDir(){
    return direction;
}

void Entity::Move(){
    if (direction.x > 1 || direction.y > 1){
        std::cout << "Err : Direction too large.\n";
        direction.x = direction.x / direction.x;
        direction.y = direction.y / direction.y;
    }
    position.x += direction.x;
    position.y += direction.y;
}