#include "raylib.h"
#include <vector>

struct Object3D {
    Vector3 position;
    Vector3 size;
    Color color;
};


// make
// ./collision_sandbox

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

    Object3D player = {
        { 0.0f, 1.0f, 0.0f },
        { 2.0f, 2.0f, 2.0f },
        BLUE

    };

    std::vector<Object3D> objects = {
        { { 4.0f, 1.0f, 0.0f }, { 2.0f, 2.0f, 2.0f }, RED },
        { { -4.0f, 1.0f, 0.0f }, { 2.0f, 2.0f, 2.0f }, GREEN },
        { { 0.0f, 1.0f, 4.0f }, { 2.0f, 2.0f, 2.0f }, ORANGE }
    };


    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_D)) player.position.x += 0.1f;
        if (IsKeyDown(KEY_A)) player.position.x -= 0.1f;
        if (IsKeyDown(KEY_W)) player.position.z -= 0.1f;
        if (IsKeyDown(KEY_S)) player.position.z += 0.1f;

        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode3D(camera);

        DrawPlane({ 0.0f, 0.0f, 0.0f }, { 20.0f, 20.0f }, DARKGRAY);
        DrawGrid(20, 1.0f);

        DrawCube(
            player.position,
            player.size.x,
            player.size.y,
            player.size.z,
            player.color
        );
        DrawCubeWires(
            player.position,
            player.size.x,
            player.size.y,
            player.size.z,
            RAYWHITE
        );

        for (const Object3D& obj : objects) {
            DrawCube(
                obj.position,
                obj.size.x,
                obj.size.y,
                obj.size.z,
                obj.color
            );
            DrawCubeWires(
                obj.position,
                obj.size.x,
                obj.size.y,
                obj.size.z,
                RAYWHITE
            );
        }

        EndMode3D();

        DrawText("WASD to move cube", 20, 20, 20, RAYWHITE);
        DrawText("Day 3: first 3D scene", 20, 50, 20, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}