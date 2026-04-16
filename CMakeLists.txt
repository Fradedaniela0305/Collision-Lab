cmake_minimum_required(VERSION 3.15)
project(CollisionSandbox)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)
find_package(Catch2 3 REQUIRED)

add_executable(collision_sandbox
    src/main.cpp
    src/collision.cpp
)

target_include_directories(collision_sandbox PRIVATE src)
target_link_libraries(collision_sandbox raylib)

add_executable(collision_tests
    tests/test_collision.cpp
    src/collision.cpp
)

target_include_directories(collision_tests PRIVATE src)
target_link_libraries(collision_tests Catch2::Catch2WithMain)

enable_testing()
include(CTest)
include(Catch)
catch_discover_tests(collision_tests)