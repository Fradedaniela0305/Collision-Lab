#include "raylib.h"

int main() {
    const int screenWidth = 1000;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "Collision Sandbox");
    SetTargetFPS(60);

    Camera3D camera = { 0 };
    camera.position = { 6.0f, 6.0f, 6.0f };
    camera.target = { 0.0f, 1.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Vector3 cubePosition = { 0.0f, 1.0f, 0.0f };
    Vector3 cubeSize = { 2.0f, 2.0f, 2.0f };

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_D)) cubePosition.x += 0.1f;
        if (IsKeyDown(KEY_A)) cubePosition.x -= 0.1f;
        if (IsKeyDown(KEY_W)) cubePosition.z -= 0.1f;
        if (IsKeyDown(KEY_S)) cubePosition.z += 0.1f;

        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode3D(camera);

        DrawPlane({ 0.0f, 0.0f, 0.0f }, { 20.0f, 20.0f }, DARKGRAY);
        DrawGrid(20, 1.0f);

        DrawCube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, BLUE);
        DrawCubeWires(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, RAYWHITE);

        EndMode3D();

        DrawText("WASD to move cube", 20, 20, 20, RAYWHITE);
        DrawText("Day 3: first 3D scene", 20, 50, 20, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}