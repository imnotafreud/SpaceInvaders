#include "spaceship.h"
#include <iostream>


SpaceShip::SpaceShip()
{
    image = LoadTexture("textures/spaceship.png");
    position = {100,100};
}

void SpaceShip::Draw()
{
    DrawTextureV(image, position, WHITE);
}

void SpaceShip::MoveLeft()
{
}

void SpaceShip::MoveRight()
{
}

void SpaceShip::FireLaser()
{
}

SpaceShip::~SpaceShip()
{
    std::cout << "unload spaceship" << std::endl;
    UnloadTexture(image);
}
