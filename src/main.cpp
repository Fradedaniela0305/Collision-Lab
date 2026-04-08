#include "raylib.h"

int main() {
    const int screenWidth = 1000;
    const int screenHeight = 700;


    InitWindow(screenWidth, screenHeight, "Collision Sandbox");
    SetTargetFPS(60);

    int boxX = 400;
    int boxY = 300;
    int boxSpeed = 5;

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_RIGHT)) boxX += boxSpeed;
        if (IsKeyDown(KEY_LEFT)) boxX -= boxSpeed;
        if (IsKeyDown(KEY_UP)) boxY -= boxSpeed;
        if (IsKeyDown(KEY_DOWN)) boxY += boxSpeed;

        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Day 2",10,10,10, RAYWHITE);

        DrawRectangle(boxX, boxY, 100, 100, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;

}