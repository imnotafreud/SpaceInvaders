#include "spaceship.h"
#include <iostream>


SpaceShip::SpaceShip()
{
    image = LoadTexture("textures/spaceship.png");
    position = {(GetScreenWidth()- image.width)/2,
                (GetScreenHeight()- image.height - 100)};
    lastFireTime = 0.0;
}

void SpaceShip::Draw()
{
    DrawTextureV(image, position, WHITE);
}

void SpaceShip::MoveLeft()
{
    position.x -= speed;
    if(position.x<25)
    {
        position.x = 25;
    }
}

void SpaceShip::MoveRight()
{
    position.x += speed;
    if(position.x > GetScreenWidth() - image.width - 25)
    {
        position.x = GetScreenWidth() - image.width - 25;
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

Rectangle SpaceShip::getRect()
{
    return {position.x, position.y, float(image.width), float(image.height)};
}

void SpaceShip::Reset()
{
        position = {(GetScreenWidth()- image.width)/2,
        (GetScreenHeight()- image.height - 100)};
        lasers.clear();
}

SpaceShip::~SpaceShip()
{
    std::cout << "unload spaceship" << std::endl;
    UnloadTexture(image);
}
