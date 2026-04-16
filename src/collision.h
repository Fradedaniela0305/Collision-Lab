#pragma once
#include "raylib.h"


struct Box {
    Vector3 position;
    Vector3 size;
};



bool checkCollision(const Box& a, const Box& b);