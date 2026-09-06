# Collision Lab

A small C++17 collision detection sandbox built with raylib. Move a cube through a 3D scene and watch it turn red when it touches or overlaps another cube.

The project demonstrates axis-aligned bounding box (AABB) collision detection, with unit tests written using Catch2.

## Features

- A 3D scene with a movable player cube and three stationary cubes.
- WASD movement across the XZ plane.
- Visual collision feedback: blue when clear, red when colliding.
- AABB checks across all three axes, including contact at boundaries.
- Unit tests for overlapping, touching, separated, and contained boxes, plus one-dimensional interval checks.

Collision detection currently changes the player's color only. Cubes can pass through each other; there is no collision response or physics simulation.

## Requirements

- A C++17-compatible compiler.
- CMake 3.15 or newer.
- raylib, installed with a CMake package configuration.
- Catch2 version 3, installed with its CMake integration.
- A graphical desktop environment to run the sandbox.

Both raylib and Catch2 are required by the current CMake configuration. Dependencies must be installed separately; the build does not download them.

## Build and run

From the project root:

```sh
cmake -S . -B build
cmake --build build
./build/collision_sandbox
```

## Controls

| Key | Action |
| --- | --- |
| W | Move along negative Z |
| S | Move along positive Z |
| A | Move along negative X |
| D | Move along positive X |
| Escape | Close the sandbox |

The camera is fixed. The window opens at 1000 × 700 pixels with a target of 60 FPS. Movement is currently a fixed distance per frame.

## Run tests

After building:

```sh
ctest --test-dir build --output-on-failure
```

For a multi-configuration build:

```sh
ctest --test-dir build -C Debug --output-on-failure
```

The suite contains 12 test cases and runs without opening a graphics window.

## How collision detection works

Each `Box` has a center position and a full size (width, height, and depth). On each axis, its interval is:

```text
minimum = position - size / 2
maximum = position + size / 2
```

Two intervals overlap when the larger minimum is less than or equal to the smaller maximum. `checkCollision` returns true only when this condition holds on X, Y, and Z.

The inclusive comparison means boxes touching at a face, edge, or corner count as colliding. Boxes are axis-aligned; rotation is not represented.

## Project layout

```text
Collision-Lab/
├── CMakeLists.txt           # Application and test build targets
├── src/
│   ├── main.cpp            # Window, scene, input, and rendering
│   ├── object.h            # Renderable cube data
│   ├── collision.h         # Box type and collision function declarations
│   ├── collision.cpp       # Interval and AABB collision checks
│   ├── scene.h             # Scene-loading declaration (in progress)
│   └── scene.cpp           # Scene-loading implementation (in progress)
├── tests/
│   └── test_collision.cpp  # Catch2 unit tests
└── assets/                 # Scene assets under development
```

The active scene is defined directly in `src/main.cpp`. The scene-loading files are unfinished and are not included in the CMake targets; JSON scene loading is not currently available. Their reference to `nlohmann/json.hpp` is not a dependency of the active build.

To experiment, edit the player and object positions or sizes in `src/main.cpp`, then rebuild. Collision behavior lives in `src/collision.cpp`, with corresponding tests in `tests/test_collision.cpp`.
