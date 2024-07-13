#pragma once
#include "raylib.h"
#include "laser.h"
#include <vector>

class SpaceShip
{
    public:
        SpaceShip();

        void Draw();
        void MoveLeft();
        void MoveRight();
        void FireLaser();
        std::vector<Laser> lasers;
        Rectangle getRect();
        ~SpaceShip();
    private:
    Texture2D image;
    Vector2 position;
    int speed{7};
    double lastFireTime;
    
};