#include "game.h"
#include <iostream>

Game::Game()
{
    obstacles = CreateObstacles();
    aliens = CreateAliens();
    aliensDirection = 1;
    timeLastAlienFired = 0;
    mysteryShipSpawnInterval = GetRandomValue(10, 20);
    timeLastSpawn = 0;
}

Game::~Game()
{
    Alien::UnloadImages();
}

void Game::Update()
{
    double currentTime = GetTime();
    if (currentTime - timeLastSpawn > mysteryShipSpawnInterval)
    {
        mysteryship.Spawn();
        timeLastSpawn = GetTime();
        mysteryShipSpawnInterval = GetRandomValue(10, 20);
    }
    for (auto &laser : spaceship.lasers)
    {
        laser.Update();
    }

    MoveAliens();
    AlienShootLaser();
    for (auto &laser : alienLasers)
    {
        laser.Update();
    }
    // std::cout << spaceship.lasers.size() << std::endl;

    DeleteInactiveLasers();
    mysteryship.Update();
    CheckForCollisions();
}

void Game::Draw()
{
    spaceship.Draw();

    for (auto &laser : spaceship.lasers)
    {
        laser.Draw();
    }
    for (auto &obstacle : obstacles)
    {
        obstacle.Draw();
    }
    for (auto &alien : aliens)
    {
        alien.Draw();
    }
    for (auto &laser : alienLasers)
    {
        laser.Draw();
    }
    mysteryship.Draw();
}

void Game::HandleInput()
{
    if (IsKeyDown(KEY_LEFT))
    {
        spaceship.MoveLeft();
    }
    else if (IsKeyDown(KEY_RIGHT))
    {
        spaceship.MoveRight();
    }
    if (IsKeyDown(KEY_SPACE))
    {
        spaceship.FireLaser();
    }
}

void Game::CheckForCollisions()
{
    // spaceship lasers
    for (auto &laser : spaceship.lasers)
    {
        auto it = aliens.begin();
        while (it != aliens.end())
        {
            if (CheckCollisionRecs(it->getRect(), laser.getRect()))
            {
                it = aliens.erase(it);
                laser.active = false;
            }
            else
            {
                ++it;
            }
        }

        for (auto &obstacle : obstacles)
        {
            auto it = obstacle.blocks.begin();
            while (it != obstacle.blocks.end())
            {
                if (CheckCollisionRecs(it->getRect(), laser.getRect()))
                {
                    it = obstacle.blocks.erase(it);
                    laser.active = false;
                }
                else
                {
                    ++it;
                }
            }
        }

        if (CheckCollisionRecs(mysteryship.getRect(), laser.getRect()))
        {
            laser.active = false;
            mysteryship.alive = false;
        }
    }
    // aliens lasers
    for (auto &laser : alienLasers)
    {
        if (CheckCollisionRecs(laser.getRect(), spaceship.getRect()))
        {
            laser.active = false;
            std::cout << "Spacehip hit" << std::endl;
        }
        for (auto &obstacle : obstacles)
        {
            auto it = obstacle.blocks.begin();
            while (it != obstacle.blocks.end())
            {
                if (CheckCollisionRecs(it->getRect(), laser.getRect()))
                {
                    it = obstacle.blocks.erase(it);
                    laser.active = false;
                }
                else
                {
                    ++it;
                }
            }
        }
    }

    // alien collision with obstacles
    for (auto &alien : aliens)
    {
        for (auto &obstacle : obstacles)
        {
            auto it = obstacle.blocks.begin();
            while ((it != obstacle.blocks.end()))
            {
                if (CheckCollisionRecs(it->getRect(), alien.getRect()))
                {
                    it = obstacle.blocks.erase(it);
                }
                else
                {
                    it++;
                }
            }
        }
        if (CheckCollisionRecs(alien.getRect(), spaceship.getRect()))
        {
            std::cout << "Spaceship collided with alien" << std::endl;
        }
    }
}

void Game::DeleteInactiveLasers()
{
    for (auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();)
    {
        if (!it->active)
        {
            it = spaceship.lasers.erase(it);
        }
        else
        {
            ++it;
        }
    }
    for (auto it = alienLasers.begin(); it != alienLasers.end();)
    {
        if (!it->active)
        {
            it = alienLasers.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

//                          OBSTACLES

std::vector<Obstacle> Game::CreateObstacles()
{
    int obstWidth = Obstacle::grid[0].size() * 3;
    float gap = (GetScreenWidth() - 4 * obstWidth) / 5.0;
    for (int i = 0; i < 4; i++)
    {
        float offsetX = (i + 1) * gap + i * obstWidth;
        obstacles.push_back(Obstacle({offsetX, GetScreenHeight() - 100}));
    }
    return obstacles;
}

//                          ALIENS

std::vector<Alien> Game::CreateAliens()
{
    std::vector<Alien> aliens;
    for (int row = 0; row < 5; row++)
    {
        for (int column = 0; column < 11; column++)
        {
            int alienType;
            if (row == 0)
            {
                alienType = 3;
            }
            else if (row == 1 || row == 2)
            {
                alienType = 2;
            }
            else
            {
                alienType = 1;
            }
            int cellSize = 55;
            float x = column * cellSize + 75;
            float y = row * cellSize + 110;
            aliens.push_back(Alien(alienType, {x, y}));
        }
    }

    return aliens;
}

void Game::MoveAliens()
{
    for (auto &alien : aliens)
    {
        if (alien.position.x + alien.alienImages[alien.type - 1].width > GetScreenWidth())
        {
            aliensDirection = -1;
            MoveDownAleins(4);
        }
        if (alien.position.x < 0)
        {
            aliensDirection = 1;
            MoveDownAleins(4);
        }
        alien.Update(aliensDirection);
    }
}

void Game::MoveDownAleins(int distance)
{
    for (auto &alien : aliens)
    {
        alien.position.y += distance;
    }
}

void Game::AlienShootLaser()
{
    double currentTime = GetTime();
    if (currentTime - timeLastAlienFired >= alienLaserShootInterval && !aliens.empty())
    {
        int randomIndex = GetRandomValue(0, aliens.size() - 1);
        Alien &alien = aliens[randomIndex];
        Vector2 laserPos = {alien.position.x + alien.alienImages[alien.type - 1].width / 2,
                            alien.position.y + alien.alienImages[alien.type - 1].height};
        alienLasers.push_back(Laser(laserPos, 6));
        timeLastAlienFired = GetTime();
    }
}