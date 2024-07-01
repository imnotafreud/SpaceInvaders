#include "raylib.h"
#include "game.h"
#include "laser.h"






int main()
{

     Color grey = {29, 29, 27, 255};
     int windowWidth = 750;
     int windowHeight = 700;

     //prepare window
     InitWindow(windowWidth, windowHeight, "Space Invaders");
     SetTargetFPS(60);
     Game game;

     
     //main loop
     while (!WindowShouldClose())
     {
          DrawFPS(0, 0);
          game.HandleInput();
          game.Update();


          BeginDrawing();
          //draw background
          ClearBackground(grey);

          game.Draw();


      EndDrawing();
     }

     CloseWindow();
} 