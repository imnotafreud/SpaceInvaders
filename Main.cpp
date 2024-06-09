#include "raylib.h"
#include "spaceship.h"





int main()
{

     Color grey = {29, 29, 27, 255};
     int windowWidth = 750;
     int windowHeight = 700;

     //prepare window
     InitWindow(windowWidth, windowHeight, "Space Invaders");
     SetTargetFPS(60);
     SpaceShip ship = SpaceShip();     
     
     
     //main loop
     while (!WindowShouldClose())
     {
          
          float dt = GetFrameTime();
          DrawFPS(0, 0);
          BeginDrawing();
          ClearBackground(grey);
          //draw background
          ship.Draw();


      EndDrawing();
     }

     CloseWindow();
} 