cmake_minimum_required(VERSION 3.15)
project(CollisionSandbox)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(collision_sandbox src/main.cpp)

find_package(raylib REQUIRED)

target_link_libraries(collision_sandbox raylib)