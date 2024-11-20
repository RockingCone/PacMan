#pragma once
#include "entity.h"

class Ghost : public Entity
{
    protected:
    private:
        /// @brief Color of Ghost
        Color color;
        /// @brief Cellsize of map
        unsigned short int size;
    public:
        ~Ghost();
        Ghost() : Entity() {};
        Ghost(Vector2 pos, Vector2 dir, Color col, unsigned short int newSize) : Entity(pos, dir) {color = col; size = newSize;};
        void Render(float scale, Camera2D camera);
};