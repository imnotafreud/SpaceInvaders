#include "spaceship.h"
#include <iostream>


SpaceShip::SpaceShip()
{
    image = LoadTexture("textures/spaceship.png");
    position = {(GetScreenWidth()- image.width)/2,
                (GetScreenHeight()- image.height)};
    lastFireTime = 0.0;
}

void SpaceShip::Draw()
{
    DrawTextureV(image, position, WHITE);
}

void SpaceShip::MoveLeft()
{
    position.x -= speed;
    if(position.x<0)
    {
        position.x = 0;
    }
}

void SpaceShip::MoveRight()
{
    position.x += speed;
    if(position.x > GetScreenWidth() - image.width)
    {
        position.x = GetScreenWidth() - image.width;
    }
}

void SpaceShip::FireLaser()
{
    if(GetTime() - lastFireTime >= 0.35)
    {
        lasers.push_back(Laser({position.x +image.width/2 - 2, position.y},-6));
        lastFireTime = GetTime();
    }

}

SpaceShip::~SpaceShip()
{
    std::cout << "unload spaceship" << std::endl;
    UnloadTexture(image);
}
