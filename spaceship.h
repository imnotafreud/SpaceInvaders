#pragma once
#include "raylib.h"

class SpaceShip
{
    public:
        SpaceShip();

        void Draw();
        void MoveLeft();
        void MoveRight();
        void FireLaser();

        ~SpaceShip();
    private:
    Texture2D image;
    Vector2 position;
    
};