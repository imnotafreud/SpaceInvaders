#include "game.h"
#include <iostream>

Game::Game()
{
    obstacles = CreateObstacles();
}

Game::~Game()
{
}

void Game::Update()
{
    for(auto& laser: spaceship.lasers)
    {
        laser.Update();
    }

    DeleteInactiveLasers();
    std::cout << spaceship.lasers.size() << std::endl;
}

void Game::Draw()
{
    spaceship.Draw();

    for(auto& laser: spaceship.lasers)
    {
        laser.Draw();
    }
    for(auto& obstacle : obstacles)
    {
        obstacle.Draw();
    }
}

void Game::HandleInput()
{
    if(IsKeyDown(KEY_LEFT))
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

void Game::DeleteInactiveLasers()
{
    for(auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();)
    {
        if (!it -> active)
        {
            it = spaceship.lasers.erase(it);
        }
        else{
            ++it;
        }
    }    
}

std::vector<Obstacle> Game::CreateObstacles()
{
    int obstWidth = Obstacle::grid[0].size() * 3;
    float gap = (GetScreenWidth() - 4 * obstWidth) / 5.0;
    for(int i=0; i < 4; i++)
    {
        float offsetX = (i+1) * gap + i * obstWidth;
        obstacles.push_back(Obstacle({offsetX, GetScreenHeight() - 100}));
    }
    return obstacles;
}
