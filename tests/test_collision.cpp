#include <catch2/catch_test_macros.hpp>
#include "collision.h"

// cmake ..
// make
// ctest

TEST_CASE("Overlapping boxes collide") {
    Box a{{0.0f, 0.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};
    Box b{{1.0f, 0.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};

    REQUIRE(checkCollision(a, b) == true);

}