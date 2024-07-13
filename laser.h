#pragma once
#include <raylib.h>

class Laser
{

public:
    Laser(Vector2 pos, int speed);
    ~Laser();
    void Update();
    void Draw();
    bool active;
    Rectangle getRect();
private:
    Vector2 position;
    int sp;
};

