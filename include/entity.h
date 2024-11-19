#pragma once
#include "raylib.h"
#include "resource_dir.h"

class Entity
{
    protected:
    private:
        /// @brief Pixel Coordinates of Entity
        Vector2 position;
        /// @brief Direction Entity is facing
        Vector2 direction;
    public:
        ~Entity();
        Entity();
        Entity(Vector2 pos, Vector2 dir);
        /// @brief Sets Direction of Entity
        /// @param dir(direction) 
        void SetDir(Vector2 dir);
        /// @brief Returns Pixel Coordinates of Entity
        /// @return Position
        Vector2 GetPos();
        /// @brief Returns Direction of Movement of Entity
        /// @return Direction
        Vector2 GetDir();
        /// @brief Moves Entity One pixel
        void Move(float scale);
        /// @brief Sets Position
        void SetPos(Vector2 pos);
};