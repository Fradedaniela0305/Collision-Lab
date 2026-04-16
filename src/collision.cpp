#include "collision.h"
#include <utility>

// cmake ..
// make
// ctest


/**
 * @brief Checks whether two axis-aligned bounding boxes (AABB) collide.
 *
 * Each box is defined by a center position and size. The function determines
 * whether the two boxes overlap or touch along all three axes (x, y, z).
 *
 * @param a [in] The first box.
 * @param b [in] The second box.
 *
 * @return true if the boxes overlap or touch; false otherwise.
 */

bool checkCollision(const Box& a, const Box& b) {
 
    bool overlapX = overlap(a.position.x, a.size.x, b.position.x, b.size.x);
    bool overlapY = overlap(a.position.y, a.size.y, b.position.y, b.size.y);
    bool overlapZ = overlap(a.position.z, a.size.z, b.position.z, b.size.z);

    return overlapX && overlapY && overlapZ;
}

/**
 * Helper function to check if two intervals overlap on a single axis.
 * Based on the center position and the total size (width/height/depth).
 */

bool overlap(float positionA, float sizeA, float positionB, float sizeB) {

    float aLeft = positionA - sizeA / 2;
    float aRight = positionA + sizeA / 2;

    float bLeft = positionB - sizeB / 2;
    float bRight = positionB + sizeB / 2;

    float right = fmin(aRight, bRight);
    float left = fmax(aLeft, bLeft);

    return left <= right;

}

