#pragma once
#include "spaceship.h"
#include "obstacle.h"
#include "alien.hpp"
#include "mysteryship.hpp"

class Game
{
public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void HandleInput();
    void CheckForCollisions();
    bool run;
    void PauseGame();
    bool pause;
private:
    SpaceShip spaceship;
    std::vector<Obstacle> CreateObstacles();
    std::vector<Alien> CreateAliens();
    void MoveAliens();
    void MoveDownAleins(int distance);
    void DeleteInactiveLasers();
    void AlienShootLaser();
    void GameOver();
    void Reset();
    void InitGame();
    std::vector<Obstacle> obstacles;
    std::vector<Alien> aliens;
    int aliensDirection;
    std::vector<Laser> alienLasers;
    constexpr static float alienLaserShootInterval = 0.15;
    float timeLastAlienFired;
    MysteryShip mysteryship;
    float mysteryShipSpawnInterval;
    float timeLastSpawn;
    int lives;

};