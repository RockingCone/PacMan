#pragma once
#include "entity.cpp"

class Pacman : public Entity{
    protected:
    private:
        /// @brief Color of pacman. Yellow by default.
        Color color;
        /// @brief Radius of pacman in pixels.
        unsigned short int size;
        /// @brief The Frame of animation Pacman is on. This determines how open his mouth is. His mouth is closed at frame=0.
        unsigned short int frame;
    public:
        ~Pacman();
        Pacman();
        /// @brief Renders Pacman. Should be called every frame.
        void Render(Color background);
};