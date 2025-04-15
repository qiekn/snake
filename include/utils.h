#pragma once

#include "raylib.h"
#include "specs.h"

namespace snake::utils {

bool inBounds(const Vector2 &position);
Vector2 generateRandomPosition(const int xMax = specs::cellsPerRow - 1,
                               const int yMax = specs::cellsPerColumn - 1);

}  // namespace snake::utils
