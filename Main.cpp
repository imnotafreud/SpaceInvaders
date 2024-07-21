#include "raylib.h"
#include "game.h"
#include "laser.h"

int main()
{

     Color grey = {29, 29, 27, 255};
     Color yellow = {243, 216, 63, 255};
     int offset = 50;
     int windowWidth = 750;
     int windowHeight = 700;

     // prepare window
     InitWindow(windowWidth + offset, windowHeight + 2 * offset, "Space Invaders");
     SetTargetFPS(60);
     Game game;

     // main loop
     while (!WindowShouldClose())
     {
          DrawFPS(0, 0);
          //pause game
          if (IsKeyPressed(KEY_P))
          {
               game.PauseGame();
          }
          if (!game.pause)
          {
               game.HandleInput();
               game.Update();
          }
          BeginDrawing();
          // draw background
          ClearBackground(grey);
          DrawRectangleRoundedLines({10, 10, 780, 780}, 0.18f, 20, 2, yellow);
          DrawLineEx({25, 730}, {775, 730}, 3, yellow);
          game.Draw();

          EndDrawing();
     }

     CloseWindow();
}