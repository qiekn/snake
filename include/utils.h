#pragma once

#include "raylib.h"
#include "specs.h"

namespace snake::utils {

bool InBounds(const Vector2 &position);
Vector2 GenerateRandomPosition(const int xMax = specs::cells_per_row - 1,
                               const int yMax = specs::cells_per_column - 1);

}  // namespace snake::utils
