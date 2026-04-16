#include <catch2/catch_test_macros.hpp>
#include "collision.h"

// cmake ..
// make
// ctest

#include <catch2/catch_test_macros.hpp>
#include "collision.h"

TEST_CASE("Boxes overlap normally") {
    Box a{{0.0f, 0.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};
    Box b{{1.0f, 0.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};

    REQUIRE(checkCollision(a, b) == true);
}

TEST_CASE("Boxes touching exactly at one face collide") {
    Box a{{0.0f, 0.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};
    Box b{{2.0f, 0.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};

    REQUIRE(checkCollision(a, b) == true);
}

TEST_CASE("Boxes separated by a tiny gap do not collide") {
    Box a{{0.0f, 0.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};
    Box b{{2.1f, 0.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};

    REQUIRE(checkCollision(a, b) == false);
}

TEST_CASE("Boxes separated by one unit do not collide") {
    Box a{{0.0f, 0.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};
    Box b{{3.0f, 0.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};

    REQUIRE(checkCollision(a, b) == false);
}

TEST_CASE("Boxes overlapping by one unit collide") {
    Box a{{0.0f, 0.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};
    Box b{{1.0f, 0.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};

    REQUIRE(checkCollision(a, b) == true);
}

TEST_CASE("Boxes separated only on the y axis do not collide") {
    Box a{{0.0f, 0.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};
    Box b{{0.0f, 3.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};
    REQUIRE(checkCollision(a,b) == false);
}

TEST_CASE("Boxes separated only on the z axis do not collide") {
    Box a{{0.0f, 0.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};
    Box b{{0.0f, 0.0f, 3.0f}, {2.0f, 2.0f, 2.0f}};

    REQUIRE(checkCollision(a, b) == false);
}

TEST_CASE("A box completely inside another box collides") {
    Box a{{0.0f, 0.0f, 0.0f}, {6.0f, 6.0f, 6.0f}};
    Box b{{0.0f, 0.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};

    REQUIRE(checkCollision(a, b) == true);
}

TEST_CASE("1D intervals overlap normally") {
    REQUIRE(overlap(0.0f, 2.0f, 1.0f, 2.0f) == true);
}

TEST_CASE("1D intervals separated do not overlap") {
    REQUIRE(overlap(0.0f, 2.0f, 3.0f, 2.0f) == false);
}

TEST_CASE("1D intervals touching at boundary overlap") {
    REQUIRE(overlap(0.0f, 2.0f, 2.0f, 2.0f) == true);
}

TEST_CASE("1D intervals with tiny gap do not overlap") {
    REQUIRE(overlap(0.0f, 2.0f, 2.1f, 2.0f) == false);
}