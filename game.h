#pragma once
#include "spaceship.h"
#include "obstacle.h"

class Game
{
public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void HandleInput();

private:
    SpaceShip spaceship;
    std::vector<Obstacle> CreateObstacles();
    void DeleteInactiveLasers();
    std::vector<Obstacle> obstacles;
};