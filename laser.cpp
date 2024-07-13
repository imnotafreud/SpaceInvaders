#include "laser.h"
#include <iostream>

Laser::Laser(Vector2 pos, int speed)
{
    position = pos;
    sp = speed;
    active = true;
}

Laser::~Laser()
{
}

void Laser::Update()
{
    position.y += sp;
    if (active)
    {
        if (position.y > GetScreenHeight() || position.y < 0)
        {
            active = false;
            //std::cout << "laser inactive" << std::endl;
        }
    }
}

void Laser::Draw()
{
    if (active)
    {
        DrawRectangle(position.x, position.y, 4, 15, YELLOW);
    }

}

Rectangle Laser::getRect()
{
    Rectangle rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.width = 4;
    rect.height = 15;
    return rect;
}
