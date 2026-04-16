#pragma once
#include "raylib.h"


struct Box {
    Vector3 position;
    Vector3 size;
};

bool overlap(float positionA, float sizeA, float positionB, float sizeB);

bool checkCollision(const Box& a, const Box& b);

